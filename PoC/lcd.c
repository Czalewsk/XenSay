#include "XenSay.h"

void    lcd_clear(void);

void        lcd_init_rst(void)
{
    s16 i = 0;
    TRISGbits.TRISG9 = 0;
    LATGbits.LATG9 = 1;
    LATGbits.LATG9 = 0;
    while (i++ < 100);
    LATGbits.LATG9 = 1;
}

void    lcd_write_line(char *str, s8 line)
{
//    i2c_start();
//    i2c_fillBuffer(ADDR);
    i2c_fillBuffer(0x80, 0);
    if (line == 0)
        i2c_fillBuffer(0x80, 0);
    else
        i2c_fillBuffer(0xC0, 0);
    while (*str && *(str + 1))
    {
        i2c_fillBuffer(0xC0, 0);
        i2c_fillBuffer(*str++, 0);
    }
    i2c_fillBuffer(0x40, 0);
    i2c_fillBuffer(*str, 1);
//    i2c_stop();
}

void        lcd_init(void)
{
    u32 t = 50000;

 //   i2c_idle();
   // i2c_start();
 //   i2c_fillBuffer(ADDR);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x38, 0);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x35, 0);  //i2c_fillBuffer(0x39);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x14, 0);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x74, 0);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x54, 0);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x6F, 0);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x0C, 0);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x01, 0);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x06, 0);
    i2c_fillBuffer(0x00, 0);
    i2c_fillBuffer(0x0C, 0);
//    i2c_stop();
    lcd_clear();
//    lcd_write_line("  X e n  S a y ", 0);
//    while (t--);
}

void    lcd_init_end(void)
{
//    i2c_start();
 //   i2c_fillBuffer(ADDR);
    i2c_fillBuffer(0, 0);
    i2c_fillBuffer(0x39, 1);
//    i2c_stop();
}

void    lcd_clear(void)
{
    u8 t = 50;

//    i2c_start();
//    i2c_fillBuffer(ADDR);
    i2c_fillBuffer(0x00, 0);
    i2c_fillBuffer(0x01, 1);
//    i2c_stop();
    while (t--);
}

void    lcd_write_nb(char *str, u8 line, s8 icase)
{
    if (line > 1 || icase > 15)
        return ;
//    i2c_start();
 //   i2c_fillBuffer(ADDR);
    i2c_fillBuffer(0x80, 0);
    if (line == 0)
        i2c_fillBuffer(128 + icase, 0);
    else
        i2c_fillBuffer(192 + icase, 0);
    while (*str && *(str + 1))
    {
        i2c_fillBuffer(0xC0, 0);
        i2c_fillBuffer(*str++, 0);
    }
    i2c_fillBuffer(0x40, 0);
    i2c_fillBuffer(*str, 1);
//    i2c_stop();
}

void    lcd_cursor(s8 show, s8 blink)
{
//    i2c_start();
//    i2c_fillBuffer(ADDR);
    i2c_fillBuffer(0x00, 0);
    if (!show && !blink)
        i2c_fillBuffer(0x0C, 1);
    else if (show && blink)
        i2c_fillBuffer(0x0F, 1);
    else if (show && !blink)
        i2c_fillBuffer(0x0E, 1);
    else
        i2c_fillBuffer(0x0D, 1);
//    i2c_stop();
}

void    lcd_create_char(void)
{
//    DelayMs(10);
//    i2c_start();
//    i2c_fillBuffer(ADDR);
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x34, 0);
//    DelayMs(10);
    i2c_fillBuffer(0x80, 0);  //Creation 1char
    i2c_fillBuffer(0x40, 0);
//    DelayMs(10);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x10, 0);
//    DelayMs(10);
    i2c_fillBuffer(0x80, 0);  //Creation 2eme char
    i2c_fillBuffer(0x48, 0);
//    DelayMs(10);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x18, 0);
//    DelayMs(10);
    i2c_fillBuffer(0x80, 0);  //Creation 3eme char
    i2c_fillBuffer(0x50, 0);
//    DelayMs(10);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1C, 0);
    i2c_fillBuffer(0x80, 0);  //Creation 4eme char
    i2c_fillBuffer(0x58, 0);
//    DelayMs(10);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1E, 0);
    i2c_fillBuffer(0x80, 0);  //Creation 5eme char
    i2c_fillBuffer(0x60, 0);
//    DelayMs(10);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1F, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1F, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1F, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1F, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1F, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1F, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1F, 0);
    i2c_fillBuffer(0x40, 0);
    i2c_fillBuffer(0x1F, 1);
//    DelayMs(10);
/*    i2c_fillBuffer(0x80); // Affichage
    i2c_fillBuffer(0x80);
    i2c_fillBuffer(0xC0);
    i2c_fillBuffer(0x0);
    i2c_fillBuffer(0xC0);
    i2c_fillBuffer(0x1);
    i2c_fillBuffer(0xC0);
    i2c_fillBuffer(0x2);
    i2c_fillBuffer(0xC0);
    i2c_fillBuffer(0x3);
    i2c_fillBuffer(0x40);
    i2c_fillBuffer(0x4);*/
//    i2c_stop();
}