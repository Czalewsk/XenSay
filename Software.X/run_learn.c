#include "XenSay.h"
#include "xformat.h"
#include "events.h"
#include "button.h"
#include "led.h"

void run_learn(void);

static u32 tabBtn[] = {
    BTN_NOTE1, BTN_NOTE2, BTN_NOTE3, BTN_NOTE4, BTN_NOTE5, BTN_NOTE6, BTN_NOTE7,
    BTN_NOTE8, BTN_NOTE9, BTN_NOTE10, BTN_NOTE11, BTN_NOTE12, BTN_NOTE13
};
static u32 tabLed[] = {
    LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7,
    LED_8, LED_9, LED_10, LED_11, LED_12, LED_13
};

static void learnReset()
{
    music_stop();
    g_led = 0x0;
}

static void onPressButtonAlway(u32 button)
{
    if (button & BTN_CFG_5)
    {
        learnReset();
        event_setState(CONFIG);
    }
}

static void onPressButtonError(u32 button)
{
    event_setState(CONFIG);
}

static void error()
{
    lcd_write_line(" Press to quit  ", 1);
    learnReset();
    setOnPressCallback(&onPressButtonError);
}

static void onPressButtonRetry(u32 button)
{
    if (button & BTN_CFG_5)
        onPressButtonAlway(button);
    else
        run_learn();

}

static void retry()
{
    lcd_write_line(" Press to retry ", 1);
    setOnPressCallback(&onPressButtonRetry);
}

static void timerTimeout()
{
    timer4Off();
    music_stop();
    lcd_write_line("    Timeout !   ", 0);
    g_led = 0xffff;
    setOnPressCallback(&error);
}

static void waitNextStep(u8 delay)
{
    u8 note = music_getStepNote();
    u8 mod = note % 12;
    g_led = tabLed[mod];
    if (delay)
        setTimer4F(&timerTimeout, (delay * 39) + 100, 7);
}

static void onPressButtonGame(u32 button)
{
    u8 i;
    
    for (i = 0; i < 13; ++i)
    {
        if (tabBtn[music_getStepNote() % 12] & button)
        {
            g_led = 0;
            music_playStep();
            break;
        }
    }
    
    onPressButtonAlway(button);
}

static void onPressButtonSelect(u32 button)
{    
    u8 *name;
    u8 *music;
    u16 size;
    
    if (button & BTN_CFG_3) // Load selected music
    {
        music = xformat_loadMusic();
        size = xformat_sizeMusic();
        if (!music)
            error();
        else
        {
            music_startStep(music, size);
            music_setOnStepEnd(&waitNextStep);
            setOnPressCallback(&onPressButtonGame);
            lcd_write_line("  Let's Fuck !  ", 0);
            waitNextStep(0);
        }
    }
    else if (button & BTN_CFG_1) // Prev
    {
        if (!(name = xformat_prevMusic()))
            error();
        lcd_shift("", 1);
        lcd_shift(name, 1);
    }
    else if (button & BTN_CFG_2) // Next
    {
        if (!(name = xformat_nextMusic()))
            error();
        lcd_shift("", 1);
        lcd_shift(name, 1);
    }
    
    onPressButtonAlway(button);
}

static void SelectMusic()
{   
    u8 *name;
    
    lcd_write_line("\177 Select Music \176", 0);
    
    if (!(name = xformat_firstMusic()))
    {
        lcd_write_line("No music in card", 0);
        error();
        return ;
    }
    
    lcd_shift(name, 1);
    
    setOnPressCallback(&onPressButtonSelect);
}

void    run_learn(void)
{
    if (!xformat_start())
    {
        error();
        return ;
    }
    
    SelectMusic();
}
