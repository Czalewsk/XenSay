#include "XenSay.h"
#include "events.h"

static  u8  config_select;

void    press_menu(u32 button)
{
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
        event_setState(game_state[config_select]);
        return ;
    }
    if (button & 0x80)
        config_select = (config_select == 0) ? 2 : config_select - 1;
    else if (button & 0x8)
        config_select = (config_select == 2) ? 0 : config_select + 1;
    lcd_write_nb(game_mode[config_select], 1, 1);
}

void    run_config(void)    //Le Menu quoi !!
{
    lcd_write_line("Select Game Mode", 0);
    lcd_write_line("\177  Free  Mode  \176", 1);
    config_select = 2;
    setOnPressCallback(&press_menu);
}
