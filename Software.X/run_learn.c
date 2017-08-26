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

static u8 tabDifficulty[] = {
    0, 5, 3, 1
};

static u8 difficulty;

static u16 stepIndex;

static void learnReset()
{
    music_stop();
    audio_setBuzzer(1);
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
    {
        g_led = 0x0;
        onPressButtonAlway(button);
    }
    else if (button & 0x1E00)
    {
        g_led = 0x0;
        setupState(MUSIC);
    }

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
        if (tabDifficulty[difficulty])
            setTimer4F(&timerTimeout, (tabDifficulty[difficulty] * 100) * 39, 7);
    }
}

static void onPressButtonGame(u32 button)
{
    u8 size;
    u8 value64;
    u8 i;
    u8 str[] = "                ";
    
    if (tabBtn[music_getStepNote() % 12] & button)
    {
        // Loading bar
        ++stepIndex;
        size = xformat_sizeMusic() / 3;
        value64 = (((float)stepIndex) / ((float)size)) * 64;   // Fucking float but change later
        for (i = 0; i < value64 / 4; ++i)
            str[i] = 4;
        if (value64 % 4)
            str[i] = value64 % 4;
        lcd_write_line(str, 1);
        
        g_led = 0x0;
        timer4Off();
        music_playStep();
    }
    else if (button & 0xFFFFE0FF)
    {
        music_stop();
        lcd_write_line("     Loose !    ", 0);
        g_led = 0xffff;
        retry();
    }
    if (button & BTN_CFG_4)
    {
        audio_setBuzzer(!audio_getBuzzer());
        lcd_clear_line(0);
        lcd_write_line("  Buzzer: ", 0);
        lcd_write_case(audio_getBuzzer() ? "yes" : "no ", 0, 10);
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
    {
        setupState(PLAY);
        return ;
    }
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
        else
        {
            lcd_shift("", 1);
            lcd_shift(name, 1);
        }
    }
    else if (button & BTN_CFG_2) // Next
    {
        if (!(name = xformat_nextMusic()))
            error();
        else
        {
            lcd_shift("", 1);
            lcd_shift(name, 1);
        }
    }
    else if (button & BTN_CFG_4) // Preview
    {
        u8 *data;
        
        if (!(data = xformat_loadMusic()))
            error();
        music_play(data, xformat_sizeMusic());
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
            music_stop();
            lcd_write_line(" Set Difficulty ", 0);
            lcd_write_line("\177     DRICC    \176", 1);
            difficulty = 0;
            setOnPressCallback(&onPressButtonDifficulty);
            break;
            
        case PLAY:
            stepIndex = 0;
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
                lcd_clear_line(1);
                g_led = tabLed[music_getStepNote() % 12];
            }
            break;
        case LOOSE:
            timer4Off();
            learnReset();
            lcd_write_line("    Loose !     ", 0);
            retry();
            break;
        case WIN:
            timer4Off();
            learnReset();
            lcd_write_line("   You Win !    ", 0);
            retry();
            break;
        case TIMEOUT:
            timer4Off();
            learnReset();
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
