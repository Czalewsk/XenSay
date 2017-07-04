#include "XenSay.h"
#include "events.h"
#include "button.h"

void    run_simon(void);

typedef enum    {
    INIT,
    DIFFICULTY,
    INIT_PLAY,
    PLAY,
    LOOSE,
    WIN,
    EXIT,
} SIMON_STATES;

static  u32      corr_btn[13] = {BTN_NOTE1, BTN_NOTE3, BTN_NOTE5, BTN_NOTE6,
                                BTN_NOTE8, BTN_NOTE10, BTN_NOTE12, BTN_NOTE13,
                                BTN_NOTE2, BTN_NOTE4, BTN_NOTE7, BTN_NOTE9,
                                BTN_NOTE11};

static  SIMON_STATES   simon_state = INIT;
static  u32            g_difficulty; // Difficultee
static  u32            pattern[100]; // Pattern Simon
static  u32            len_pattern;        // Len of simon
static  u8             show_pattern;  // affichage du pattern
static  u8             in_game;

void    exit_simon(void)
{
    timer4Off();
    g_led = 0;
    simon_state = INIT;
    event_setState(CONFIG);
}

void    difficulty_simon(u32 button)
{
    static u8  i = 4;
    char    tab[5][15] = {
        "      TIM     ",
        "     EASY     ",
        "    NORMAL    ",
        "     HARD     ",
        "    EXTREME   ",
    };

    if (button & BTN_CFG_5)
    {
        exit_simon();
        return ;
    }
    if (button & BTN_CFG_3)
    {
        g_difficulty = i;
        pattern[len_pattern++] = TMR4 % 13;
        simon_state = INIT_PLAY;
        event_setFlag(FLAG_SIMON);
        return ;
    }
    else if (button & BTN_CFG_2)
        i = (i == 4) ? 0 : i + 1;
    else if (button & BTN_CFG_1)
        i = (i == 0) ? 4 : i - 1;
    lcd_write_nb(tab[i], 1, 1);
}

void    play_simon(u32 button)
{
    static u8   index;

    if (button & BTN_CFG_5)
    {
        exit_simon();
        return ;
    }
    if (in_game == 1)
    {
        if (button & corr_btn[pattern[index]])
        {
            g_led = 1 << pattern[index];
            index++;
        }
        else
        {
            simon_state = EXIT;
            event_setFlag(FLAG_SIMON);
        }
        if (index >= len_pattern)
        {
            index = 0;
            in_game = 0;
            event_setFlag(FLAG_SIMON);
            return ;
        }
    }
    else if (in_game == -1)
    {
        simon_state = INIT;
        event_setFlag(FLAG_SIMON);
    }
    return ;
}

void    light_pattern(void)
{
    static  u8  i;

    if (!show_pattern)
        return ;
    if (i >= len_pattern)
    {
        g_led = 0;
        show_pattern = 0;
        in_game = 1;
        return ;
    }
    g_led = 1 << pattern[i++];
}

void    run_simon(void)
{
    switch(simon_state)
    {
            case(INIT):
                timer5Off();
                setTimer4F(&light_pattern, 15625, 3);
                len_pattern = 0;
                g_difficulty = 0;
                show_pattern = 0;
                in_game = 0;
                simon_state = DIFFICULTY;
            case(DIFFICULTY):
                lcd_write_line(" Set Difficulty  ", 0);
                lcd_write_line("\177              \176", 1);
                difficulty_simon(BTN_CFG_2);
                setOnPressCallback(&difficulty_simon);
                break ;
            case(INIT_PLAY):
                setOnPressCallback(&play_simon);
                simon_state = PLAY;
            case(PLAY):
                pattern[len_pattern++] = PR4 % 13;
                show_pattern = 1;
                break ;
            case(LOOSE):
                g_led = 0xFFFF;
                lcd_clear();
                lcd_write_line("Loose! Try Again", 0);
                lcd_write_line("Press to restart", 1);
                in_game = -1;
                break ;
    }
    event_clearFlag(FLAG_SIMON);
    return ;
}