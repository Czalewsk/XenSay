#include "XenSay.h"
#include "xformat.h"
#include "events.h"
#include "button.h"

static u8 state;

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
    
}

static void onPressButtonSelect(u32 button)
{
    u8 *name;
    
    if (button & BTN_CFG_1) // Ok
    {
        //setOnPressCallback(NULL);
        music_play(xformat_loadMusic(), xformat_sizeMusic());
    }
    else if (button & BTN_CFG_2) // Prev
    {
        if (!(name = xformat_prevMusic()))
            error();
        lcd_shift("", 1);
        lcd_shift(name, 1);
    }
    else if (button & BTN_CFG_3) // Next
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
