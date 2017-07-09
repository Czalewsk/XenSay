#include "XenSay.h"
#include "xformat.h"
#include "events.h"
#include "button.h"
#include "led.h"

typedef enum    {
    MUSIC,
    DIFFICULTY,
    PLAY,
    LOOSE,
    TIMEOUT,
    WIN
} LEARN_STATES;

void setupState(LEARN_STATES state);

static u32 tabBtn[] = {
    BTN_NOTE1, BTN_NOTE2, BTN_NOTE3, BTN_NOTE4, BTN_NOTE5, BTN_NOTE6, BTN_NOTE7,
    BTN_NOTE8, BTN_NOTE9, BTN_NOTE10, BTN_NOTE11, BTN_NOTE12, BTN_NOTE13
};

static u32 tabLed[] = {
    LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7,
    LED_8, LED_9, LED_10, LED_11, LED_12, LED_13
};

static u8 tabDifficulty[] = {
    0, 5, 3, 1
};

static u8 difficulty;

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
    g_led = 0x0;
    if (button & BTN_CFG_5)
        onPressButtonAlway(button);
    else
        setupState(MUSIC);

}

static void retry()
{
    lcd_write_line(" Press to retry ", 1);
    setOnPressCallback(&onPressButtonRetry);
}

static void timerTimeout()
{
    timer4Off();
    setupState(TIMEOUT);
}

static void waitNextStep(u8 delay)
{
    if (!music_getStepNote())
        setupState(WIN);
    else
    {
        g_led = tabLed[music_getStepNote() % 12];
        //if (delay)
            //setTimer4F(&timerTimeout, (delay * 39), 7);
        if (tabDifficulty[difficulty])
            setTimer4F(&timerTimeout, (tabDifficulty[difficulty] * 100) * 39, 7);
    }
}

static void onPressButtonGame(u32 button)
{
    if (tabBtn[music_getStepNote() % 12] & button)
    {
        g_led = 0;
        timer4Off();
        music_playStep();
    }
    else if (button & 0xFFFFE0FF)
    {
        timer4Off();
        music_stop();
        lcd_write_line("     Loose !    ", 0);
        g_led = 0xffff;
        retry();
    }
    
    onPressButtonAlway(button);
}

static void onPressButtonDifficulty(u32 button)
{
    u8 *diffName[] = {
        "\177     DRICC    \176",
        "\177     EASY     \176",
        "\177    MEDIUM    \176",
        "\177     HARD     \176"
    };
    
    if (button & BTN_CFG_1)
        difficulty = difficulty > 0 ? difficulty - 1 : 0;
    else if (button & BTN_CFG_2)
        difficulty = difficulty < 3 ? difficulty + 1 : 3;
    else if (button & BTN_CFG_3)
        setupState(PLAY);
    lcd_write_line(diffName[difficulty], 1);
    
    onPressButtonAlway(button);
}

static void onPressButtonSelect(u32 button)
{    
    u8 *name;
    
    if (button & BTN_CFG_3) // Load selected music
        setupState(DIFFICULTY);
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

void    setupState(LEARN_STATES state)
{
    u8 *name;
    u8 *music;
    u16 size;
    
    switch (state)
    {
        case MUSIC:
            if (!xformat_start())
            {
                error();
                return ;
            }
            lcd_write_line("\177 Select Music \176", 0);
            if (!(name = xformat_firstMusic()))
            {
                lcd_write_line("No music in card", 0);
                error();
                return ;
            }
            lcd_shift(name, 1);
            setOnPressCallback(&onPressButtonSelect);
            break;
            
        case DIFFICULTY:
            lcd_write_line(" Set Difficulty ", 0);
            lcd_write_line("\177     DRICC    \176", 1);
            difficulty = 0;
            setOnPressCallback(&onPressButtonDifficulty);
            break;
            
        case PLAY:
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
                g_led = tabLed[music_getStepNote() % 12];
            }
            break;
        case LOOSE:
            lcd_write_line("    Loose !     ", 0);
            retry();
            break;
        case WIN:
            lcd_write_line("   You Win !    ", 0);
            retry();
            break;
        case TIMEOUT:
            music_stop();
            lcd_write_line("    Timeout !   ", 0);
            g_led = 0xffff;
            retry();
            break;
    }
}

void    run_learn(void)
{
    setupState(MUSIC);
}
