#include "XenSay.h"

s8      i2c_sendAdress(void)
{
    i2c_idle();
    if (I2C1STATbits.S && !I2C1STATbits.TBF && !I2C1STATbits.TRSTAT)
        I2C1TRN = (ADDR);
    else
        return (0);
    i2c_idle();
    return (1);
}

s8      i2c_start(void)
{
    i2c_idle();
 //   if (I2C1STATbits.P)
        I2C1CONbits.SEN = 1;
 //   else
 //       return (0);
    i2c_idle();
    i2c_sendAdress();
    return (1);

}

s8      i2c_stop(void)
{
    i2c_idle();
    if (!(I2C1CON & 0x1F))
        I2C1CONbits.PEN = 1;
    else
        return (0);
    return (1);
}

void    i2c_checkSDA(void)
{
    u8  i = 0;

    TRISGbits.TRISG3 = 1;
    TRISGbits.TRISG2 = 0;
    if (PORTGbits.RG3)
        while (i++ < 9)
        {
            LATGbits.LATG2 = 0;
            LATGbits.LATG2 = 1;
        }
    TRISGbits.TRISG3 = 0;
    LATGbits.LATG2 = 0;
}

s8      i2c_init(void)
{
    u8  tmp = 0;

    i2c_checkSDA();
    I2C1CON = 0;
    I2C1BRG = 2;
    I2C1STAT = 0;
    I2C1CONbits.SIDL = 1;
    I2C1ADD = ADDR;
    I2C1CONbits.ON = 1;
    tmp = I2C2RCV;
}

