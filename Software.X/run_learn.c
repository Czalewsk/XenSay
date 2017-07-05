#include "XenSay.h"
#include "xformat.h"
#include "events.h"
#include "button.h"
#include "led.h"

static u32 tabBtn[] = {
    BTN_NOTE1, BTN_NOTE2, BTN_NOTE3, BTN_NOTE4, BTN_NOTE5, BTN_NOTE6, BTN_NOTE7,
    BTN_NOTE8, BTN_NOTE9, BTN_NOTE10, BTN_NOTE11, BTN_NOTE12, BTN_NOTE13
};
static u32 tabLed[] = {
    LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7,
    LED_8, LED_9, LED_10, LED_11, LED_12, LED_13
};

static void onPressButtonAlway(u32 button)
{
    if (button & BTN_CFG_5)
        event_setState(CONFIG);
}

static void onPressButtonError(u32 button)
{
    event_setState(CONFIG);
}

static void error()
{
    lcd_write_line(" Press to quit  ", 1);
    setOnPressCallback(&onPressButtonError);
}

static void onPressButtonGame(u32 button)
{
    onPressButtonAlway(button);
    
    u8 note = music_getStepNote();
    music_playStep();
}

static void onPressButtonSelect(u32 button)
{
    onPressButtonAlway(button);
    
    u8 *name;
    u8 *music;
    u16 size;
    
    if (button & BTN_CFG_3) // Ok
    {
        music = xformat_loadMusic();
        size = xformat_sizeMusic();
        if (!music)
            error();
        else
            setOnPressCallback(&onPressButtonGame);
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
