#include "XenSay.h"
#include "events.h"


void    game_timer_init(void)
{
    // Enable interruption timer audio
    IEC0bits.T3IE = 1;
    IPC3bits.T3IP = 5;
    IFS0bits.T3IF = 0;

    // Settings timer audio
    T3CON = 0;
    T3CONbits.TCKPS = 7; // Prescal timer
    T3CONbits.TGATE = 0;
    T3CONbits.ON = 0;
}

void    difficulty_simon(u32 button)
{
    static u8  i = 0;
    char    tab[4][15] = {
        "     EASY     ",
        "    NORMAL    ",
        "     HARD     ",
        "    EXTREME   ",
    };
    if (button & 0x40)
    {
        g_difficulty = i;
        return;
    }
    if (button & 0x80)
        i = (i == 0) ? 3 : i - 1;
    else if (button & 0x8)
        i = (i == 3) ? 0 : i + 1;
    lcd_write_nb(tab[i], 1, 1);
}

void    run_simon(void)
{
    game_timer_init(void);
    lcd_write_line(" Set Difficulty  ", 0);
    lcd_write_line("\177     EASY     \176", 1);
    setOnPressCallback(&difficulty_simon);
    //play_simon(void);
    //fail_print(void);
    
}

void    fail_print(void)
{
    
}

u8    play_simon(void)
{
    u32     lvl = 0;
    u32     rand = 0;
    //
    //  set difficuté aprés pour le moment 4 touches
    //
    
    
}