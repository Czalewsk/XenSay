#include "XenSay.h"
#include "events.h"

void    init_simon(void);

static  u32     g_difficulty; // Difficultee

static  u8      test[15][3] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12"
};

void    difficulty_simon(u32 button)
{
    u8         d;
    static u8  i = 0;
    char    tab[4][15] = {
        "     EASY     ",
        "    NORMAL    ",
        "     HARD     ",
        "    EXTREME   ",
    };

    if (button & 0x4)
    {
        timer5Off();
        g_led = 0;
        event_setState(CONFIG);
        return ;
    }
    if (button & 0x40)
    {
        timer5Off();
        g_difficulty = i;
        init_simon();
        return ;
    }
    else if (button & 0x80)
        i = (i == 0) ? 3 : i - 1;
    else if (button & 0x8)
        i = (i == 3) ? 0 : i + 1;
    lcd_write_nb(tab[i], 1, 1);
}

void    run_simon(void)
{
    lcd_write_line(" Set Difficulty  ", 0);
    lcd_write_line("\177     EASY     \176", 1);
    setOnPressCallback(&difficulty_simon);
}

void    play_simon(u32 button)
{
    g_led = g_switch;
    if (g_switch == (0x8 | 0x80))
    {
        g_led = 0;
        event_setState(CONFIG);
        return ;
    }
}

void    init_simon(void)
{
    lcd_write_line("   Let's Play   ", 0);
    lcd_clear_line(1);
    setOnPressCallback(&play_simon);
}