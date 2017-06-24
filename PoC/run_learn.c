#include "XenSay.h"
#include "sdcard.h"

static void press_learn(u32 button)
{
    
}

void    run_learn(void)
{
    //lcd_write_line("\177 Select Music \176", 0);
//    lcd_write_line("\177              \176", 1);
    lcd_write_line("Checking sdcard ", 0);
    lcd_write_line("                ", 1);
   
    if (sdcard_start())
    {
        if (sdcard_read(0))
           lcd_write_line("Done            ", 0);
    }
    //setOnPressCallback(&press_learn);
}