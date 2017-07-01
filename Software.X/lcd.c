#include "XenSay.h"
#include "i2c.h"

void    lcd_clear(void);

static  t_lcdBuff lcdBuffer;


void        lcd_init_rst(void)
{
    s16 i = 0;
    TRISBbits.TRISB7 = 0; // RESET LCD
    LATBbits.LATB7 = 1;
    LATBbits.LATB7 = 0;
    while (i++ < 100);
    LATBbits.LATB7 = 1;
}

void    lcd_write_line(char *str, s8 line)
{
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
}

void        lcd_init(void)
{
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
    i2c_fillBuffer(0x0C, 1);
    lcd_write_line("  X e n  S a y ", 0);
}

void    lcd_init_end(void)
{
    i2c_fillBuffer(0, 0);
    i2c_fillBuffer(0x39, 1);
}

void    lcd_clear(void)
{
    u8 t = 250;

    i2c_fillBuffer(0x00, 0);
    i2c_fillBuffer(0x01, 1);
    while (t--);
}

void    lcd_write_nb(char *str, u8 line, s8 icase)
{
    if (line > 1 || icase > 15)
        return ;
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
}

void    lcd_cursor(s8 show, s8 blink)
{
    i2c_fillBuffer(0x00, 0);
    i2c_fillBuffer(0x0C | ((show << 1) | blink), 1);
}

void    lcd_create_char(void)
{
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0x34, 0);
    i2c_fillBuffer(0x80, 0);  //Creation 1char
    i2c_fillBuffer(0x40, 0);
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
    i2c_fillBuffer(0x80, 0);  //Creation 2eme char
    i2c_fillBuffer(0x48, 0);
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
    i2c_fillBuffer(0x80, 0);  //Creation 3eme char
    i2c_fillBuffer(0x50, 0);
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
/*    i2c_fillBuffer(0x80, 0); // Affichage
    i2c_fillBuffer(0x80, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x0, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x1, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x2, 0);
    i2c_fillBuffer(0xC0, 0);
    i2c_fillBuffer(0x3, 0);
    i2c_fillBuffer(0x40, 0);
    i2c_fillBuffer(0x4, 1);*/
}

void    lcd_rotateBuff(void)
{
    u8 i;
    char    lcd_print[17];

    i = 0;
    while (i < 16 && lcdBuffer.buffer[lcdBuffer.index + i])
    {
        lcd_print[i] = lcdBuffer.buffer[lcdBuffer.index + i];
        i++;
    }
    while (i < 16)
        lcd_print[i++] = ' ';
    if (++lcdBuffer.index >= lcdBuffer.len)
        lcdBuffer.index = 0;
    lcd_print[16] = '\0';
    lcd_write_line(lcd_print, lcdBuffer.line);
}

void    lcd_shift(char *data, u8 line)
{
    u8  i = 0;
    t_lcdBuff   tmp;

    while (*data)
        tmp.buffer[i++] = *data++;
    if (i <= 16)
    {
        while (i < 16)
            tmp.buffer[i++] = ' ';
        tmp.buffer[i] = '\0';
        tmp.len = i;
        timer5Off();
        lcdBuffer = tmp;
        lcd_write_line(lcdBuffer.buffer, line);
        return ;
    }
    tmp.buffer[i] = '\0';
    tmp.len = i;
    tmp.index = 0;
    tmp.line = line;
    timer5Off();
    lcdBuffer = tmp;
    setTimer5F(&lcd_rotateBuff, 20625);
}

void    lcd_clear_line(u8 line)
{
    u8 i = 0;

    i2c_fillBuffer(0x80, 0);
    if (line == 0)
        i2c_fillBuffer(0x80, 0);
    else
        i2c_fillBuffer(0xC0, 0);
    while (i < 15)
    {
        i2c_fillBuffer(0xC0, 0);
        i2c_fillBuffer(' ', 0);
        i++;
    }
    i2c_fillBuffer(0x40, 0);
    i2c_fillBuffer(' ', 1);
}







