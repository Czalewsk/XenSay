#include "XenSay.h"
#include "events.h"

void    press_menu(u32 button)
{
    static u8 i = 2;
    char game_mode[3][15] = {
        " Ultra  Simon ",
        "  Learn Mode  ",
        "  Free  Mode  "
    };
    STATES game_state[3] = {
        SIMON,
        LEARN,
        FREE
    };

    if (button & 0x40)
    {
        event_setState(game_state[i]);
        return ;
    }
    if (button & 0x80)
        i = (i == 0) ? 2 : i - 1;
    else if (button & 0x8)
        i = (i == 2) ? 0 : i + 1;
    lcd_write_nb(game_mode[i], 1, 1);
}

void    run_config(void)    //Le Menu quoi !!
{
    lcd_write_line("Select Game Mode", 0);
    lcd_write_line("\177  Free  Mode  \176", 1);
    setOnPressCallback(&press_menu);
}
