#include "XenSay.h"
#include "i2c.h"

static  I2C_BUSY_FLAG   g_i2c_status = FREE_I2C;
static  s_I2Cdata       g_i2c_buffer;

void    i2c_writeBuffer(s_I2Cdata *new);

s8      i2c_sendAdress(void)
{
//    if (I2C1STATbits.S && !I2C1STATbits.TBF && !I2C1STATbits.TRSTAT)
        I2C1TRN = (ADDR);
//    else
//        return (0);
    return (1);
}

s8      i2c_start(void)
{
 //   if (I2C1STATbits.P)
    {
        g_i2c_buffer.state = ADDRESS;
        I2C1CONbits.SEN = 1;
    }
 //   else
 //       return (0);
//    i2c_sendAdress();
    return (1);

}

s8      i2c_stop(void)
{
//    if (!(I2C1CON & 0x1F))
        I2C1CONbits.PEN = 1;
  //  else
 //       return (0);
    return (1);
}

void    i2c_checkSDA(void)
{
    u8  i = 0;

    TRISGbits.TRISG3 = 1;
    TRISGbits.TRISG2 = 0;
    if (!PORTGbits.RG3)
        while (i++ < 9)
        {
            LATGbits.LATG2 = 0;
            LATGbits.LATG2 = 1;
        }
    TRISGbits.TRISG3 = 0;
    LATGbits.LATG2 = 0;
}

s8      i2c1_init(void)
{
    u8  tmp = 0;

    i2c_checkSDA();
    I2C1CON = 0;
    I2C1BRG = 10;
    I2C1STAT = 0;
    I2C1ADD = ADDR;
    tmp = I2C2RCV;
    IFS0bits.I2C1MIF = 0;
    IPC6bits.I2C1IP = 5;
    IPC6bits.I2C1IS = 1;
    IEC0bits.I2C1MIE = 1;
    I2C1CONbits.ON = 1;
}

void __attribute__ ((interrupt(IPL5AUTO))) __attribute__ ((vector(25))) i2c1_interrupt(void)
{
    IFS0bits.I2C1MIF = 0;
    switch(g_i2c_buffer.state)
    {
     //   I2C1STAT = 0;
        case (ADDRESS):
        {
            g_i2c_buffer.state = SEND_DATA;
            i2c_sendAdress();
            break ;
        }
        case (SEND_DATA):
        {
            I2C1TRN = g_i2c_buffer.data[g_i2c_buffer.index];
            g_i2c_buffer.index++;
            g_i2c_buffer.state = (g_i2c_buffer.index == g_i2c_buffer.len) ? STOP : SEND_DATA;
            break ;
        }
        case (STOP):
        {
            g_i2c_buffer.state = END;
            i2c_stop();
            break ;
        }
        case (END):
        {
            g_i2c_status = FREE_I2C;
            break ;
        }
    }
}

void    i2c_reinit(void)
{
    i2c_checkSDA();
    i2c_stop();
}

void    i2c_writeBuffer(s_I2Cdata *new)
{
    u32 timeout = 10000;

    while (g_i2c_status == BUSY_I2C && timeout--);
    if (!timeout)
        i2c_reinit();
    g_i2c_buffer = *new;
    g_i2c_status = BUSY_I2C;
    i2c_start();
}

void   i2c_fillBuffer(u8 data, u8 last)
{
    static  s_I2Cdata   i2c_buffer;
    static  u8          i;

    i2c_buffer.data[i++] = data;
    i2c_buffer.len = i;
    if (last)
    {
        i = 0;
        i2c_buffer.state = START;
        i2c_buffer.index = 0;
        i2c_writeBuffer(&i2c_buffer);
    }
}