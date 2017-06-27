#include "XenSay.h"
#include "events.h"

void    init_simon(void);

static  u32     g_difficulty; // Difficultee
static  u8      pattern[100]; // Pattern Simon
static  u8      count;        // Len of simon

static  u8      test[15][3] = {
    " 0",
    " 1",
    " 2",
    " 3",
    " 4",
    " 5",
    " 6",
    " 7",
    " 8",
    " 9",
    "10",
    "11",
    "12"
};

void    difficulty_simon(u32 button)
{
    u8         d;
    static u8  i = 4;
    char    tab[5][15] = {
        "      TIM     ",
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
        g_difficulty = i;
        init_simon();
        return ;
    }
    else if (button & 0x80)
        i = (i == 0) ? 4 : i - 1;
    else if (button & 0x8)
        i = (i == 4) ? 0 : i + 1;
    lcd_write_nb(tab[i], 1, 1);
}

void    run_simon(void)
{
    lcd_write_line(" Set Difficulty  ", 0);
    lcd_write_line("\177              \176", 1);
    difficulty_simon(0x8);
    setOnPressCallback(&difficulty_simon);
}

void    save_pattern(void)
{
    pattern[count++] = TMR4;
    light_pattern();
}

void    play_simon(u32 button)
{
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
    setTimer4F(NULL, 3906, 7);
    lcd_clear_line(1);
    setOnPressCallback(&play_simon);
}