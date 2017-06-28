#include "XenSay.h"
#include "xformat.h"
#include "events.h"
#include "button.h"

static void press_learn(u32 button)
{
    if (button & BTN_CFG_2) // Prev
    {
        u8 *name;
        if ((name = xformat_prevMusic()))
        {
            name[17] = '\0';
            lcd_write_line("                ", 0);
            lcd_write_line(name, 0);   
        }
        //xformat_nextMusic(&ptr);
    }
    else if (button & BTN_CFG_3) // Next
    {
                 
        //lcd_write_line("      D          ", 0);
        //lcd_write_line(xformat_nextMusic(&ptr), 0);
        u8 *name;
        if ((name = xformat_nextMusic()))
        {
            name[17] = '\0';
            lcd_write_line("                ", 0);
            lcd_write_line(name, 0);   
        }
    }
    else if (button & BTN_CFG_1) // OK
    {
        u8 *musicData;
        u16 musicSize;
        
        if (!(musicData = xformat_loadMusic()))
            return ;
        if (!(musicSize = xformat_sizeMusic()))
            return ;
        music_play(musicData, musicSize);
    }
}

void    run_learn(void)
{
    //lcd_write_line("\177 Select Music \176", 0);
//    lcd_write_line("\177              \176", 1);
    /*lcd_write_line("Checking sdcard ", 0);
    lcd_write_line("                ", 1);
   
    if (sdcard_start())
    {
        if (sdcard_read(0))
           lcd_write_line("Done            ", 0);
    }
      setOnPressCallback(&press_learn);
    event_setState(CONFIG);*/
    
    if (xformat_start())
    {
        u8 *name;
        if ((name = xformat_firstMusic()))
        {
            name[17] = '\0';
            lcd_write_line("                ", 0);
            lcd_write_line(name, 0);
        }
        else
            lcd_write_line("ERROR first     ", 0);
    }
    else
        lcd_write_line("ERROR START     ", 0);
    setOnPressCallback(&press_learn);
    setOnReleaseCallback(NULL);
}
