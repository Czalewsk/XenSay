#include "XenSay.h"

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
    i2c_start();
    i2c_sendByte(ADDR);
    i2c_sendByte(0x80);
    if (line == 0)
        i2c_sendByte(0x80);
    else
        i2c_sendByte(0xC0);
    while (*str && *(str + 1))
    {
        i2c_sendByte(0xC0);
        i2c_sendByte(*str++);
    }
    i2c_sendByte(0x40);
    i2c_sendByte(*str);
    i2c_stop();
}

void        lcd_init(void)
{
    u32 t = 500000;

    i2c_start();
    i2c_sendByte(ADDR);
    i2c_sendByte(0x80);
    i2c_sendByte(0x38);
    i2c_sendByte(0x80);
    i2c_sendByte(0x35);  //i2c_sendByte(0x39);
    i2c_sendByte(0x80);
    i2c_sendByte(0x14);
    i2c_sendByte(0x80);
    i2c_sendByte(0x74);
    i2c_sendByte(0x80);
    i2c_sendByte(0x54);
    i2c_sendByte(0x80);
    i2c_sendByte(0x6F);
    i2c_sendByte(0x80);
    i2c_sendByte(0x0C);
    i2c_sendByte(0x80);
    i2c_sendByte(0x01);
    i2c_sendByte(0x80);
    i2c_sendByte(0x06);
    i2c_sendByte(0x00);
    i2c_sendByte(0x0C);
    i2c_stop();
//    lcd_clear();
    lcd_write_line("  X e n  S a y ", 0);
    while (t--);
}

void    lcd_init_end(void)
{
    i2c_start();
    i2c_sendByte(ADDR);
    i2c_sendByte(0);
    i2c_sendByte(0x39);
    i2c_stop();
}

void    lcd_clear(void)
{
    u8 t = 50;

    i2c_start();
    i2c_sendByte(ADDR);
    i2c_sendByte(0x00);
    i2c_sendByte(0x01);
    i2c_stop();
    while (t--);
}

void    lcd_write_nb(char *str, u8 line, s8 icase)
{
    if (line > 1 || icase > 15)
        return ;
    i2c_start();
    i2c_sendByte(ADDR);
    i2c_sendByte(0x80);
    if (line == 0)
        i2c_sendByte(128 + icase);
    else
        i2c_sendByte(192 + icase);
    while (*str && *(str + 1))
    {
        i2c_sendByte(0xC0);
        i2c_sendByte(*str++);
    }
    i2c_sendByte(0x40);
    i2c_sendByte(*str);
    i2c_stop();
}

void    lcd_cursor(s8 show, s8 blink)
{
    i2c_start();
    i2c_sendByte(ADDR);
    i2c_sendByte(0x00);
    if (!show && !blink)
        i2c_sendByte(0x0C);
    else if (show && blink)
        i2c_sendByte(0x0F);
    else if (show && !blink)
        i2c_sendByte(0x0E);
    else
        i2c_sendByte(0x0D);
    i2c_stop();
}

void    lcd_create_char(void)
{
//    DelayMs(10);
    i2c_start();
    i2c_sendByte(ADDR);
    i2c_sendByte(0x80);
    i2c_sendByte(0x34);
//    DelayMs(10);
    i2c_sendByte(0x80);  //Creation 1char
    i2c_sendByte(0x40);
//    DelayMs(10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x10);
//    DelayMs(10);
    i2c_sendByte(0x80);  //Creation 2eme char
    i2c_sendByte(0x48);
//    DelayMs(10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x18);
//    DelayMs(10);
    i2c_sendByte(0x80);  //Creation 3eme char
    i2c_sendByte(0x50);
//    DelayMs(10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1C);
    i2c_sendByte(0x80);  //Creation 4eme char
    i2c_sendByte(0x58);
//    DelayMs(10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1E);
    i2c_sendByte(0x80);  //Creation 5eme char
    i2c_sendByte(0x60);
//    DelayMs(10);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1F);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1F);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1F);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1F);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1F);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1F);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1F);
    i2c_sendByte(0x40);
    i2c_sendByte(0x1F);
//    DelayMs(10);
/*    i2c_sendByte(0x80); // Affichage
    i2c_sendByte(0x80);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x0);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x1);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x2);
    i2c_sendByte(0xC0);
    i2c_sendByte(0x3);
    i2c_sendByte(0x40);
    i2c_sendByte(0x4);*/
    i2c_stop();
}