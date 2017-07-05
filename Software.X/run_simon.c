#include "XenSay.h"
#include "events.h"
#include "button.h"
/*
void    play_simon(u32 button);
void    save_pattern(void);

static  u32     g_difficulty; // Difficultee
static  u32      pattern[100]; // Pattern Simon
static  u32     count;        // Len of simon
static  u8     display_pattern;

static  u32      corr_led[13] = {BTN_NOTE1, BTN_NOTE3, BTN_NOTE5, BTN_NOTE6,
                                BTN_NOTE8, BTN_NOTE10, BTN_NOTE12, BTN_NOTE13,
                                BTN_NOTE2, BTN_NOTE4, BTN_NOTE7, BTN_NOTE9,
                                BTN_NOTE11};

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

void    init_simon(void)
{
    display_pattern = 0;
    lcd_write_line("   Let's Fuck   ", 0);
    setTimer4F(NULL, 65000, 7);
    lcd_clear_line(1);
    save_pattern();
    setOnPressCallback(&play_simon);
}
 
void    difficulty_simon(u32 button)
{
    u8         d; 
    static u8  i = 4;
    char    tab[5][15] = {
        "     CAROL    ",
        "     EASY     ",
        "    NORMAL    ",
        "     HARD     ",
        "    EXTREME   ",
    };

    if (button & BTN_CFG_5)
    {
        timer5Off();
        g_led = 0;
        event_setState(CONFIG);
        return ;
    }
    if (button & BTN_CFG_3)
    {
        g_difficulty = i;
        init_simon();
        return ;
    }
    else if (button & BTN_CFG_2)
        i = (i == 0) ? 4 : i - 1;
    else if (button & BTN_CFG_1)
        i = (i == 4) ? 0 : i + 1;
    lcd_write_nb(tab[i], 1, 1);
}

void    run_simon(void)
{
    lcd_write_line(" Set Difficulty  ", 0);
    lcd_write_line("\177              \176", 1);
    difficulty_simon(BTN_CFG_1);
    setOnPressCallback(&difficulty_simon);
}

void    light_pattern(void)
{
    static  u8  i = 0;

    if (i == count)
    {
        g_led = 0;
        i = 0;
        display_pattern = 0;
        return ;
    }
    g_led = 1 << pattern[i++];
}

void    save_pattern(void)
{
   pattern[count++] = TMR4 % 13;
   //timer4Off();
   display_pattern = 1;
   setTimer4F(&light_pattern, 16000, 5);
   while (display_pattern);
   //timer4Off();
   setTimer4F(NULL, 65000, 7);
}

void    play_simon(u32 button)
{
    static u8   i;

    if (button == BTN_CFG_5)
    {
        g_led = 0;
        event_setState(CONFIG);
        return ;
    }
    if ((i == count) && (button == corr_led[i]))
    {
        save_pattern();
        i = 0;
        return ;
    }
    if (button == corr_led[i])
    {
        i++;
        g_led = pattern[i - 1];
        return ; 
    }
    else
    {
        lcd_write_line("  You  loose !  ", 1);
        i = 0;
        count = 0;
        init_simon();
        return ;
    }
}
*/