/* 
 * File:   i2c.c
 * Author: bocal
 *
 * Created on May 25, 2017, 4:01 AM
 */

#include "XenSay.h"

// Interrupt I2C priority > All || (I2C Priority == Priority (Switch)) > ALL ?

/*void    i2c_init(void)
{
    u8      tmp = 0;
    u8      i = 0;

//    TRISFbits.TRISF5 = 0;
//    LATFbits.LATF5 = 0;
//    while (i++ < 18)                      //Replace this by (If SDA is LOW -> Sends 9 clock pulse)
//    {
//        LATFbits.LATF5 = !LATFbits.LATF5;
//        cpt = 0;
//        while (cpt++ < 2000);
//    }
//    TRISFbits.TRISF4 = 0;
//    LATFbits.LATF4 = 0;
    I2C1CON = 0;
    I2C1BRG = 2;
    I2C1STAT = 0;
    I2C1CONbits.SIDL = 1;
    I2C1ADD = ADDR;
    I2C1CONbits.ON = 1;
    tmp = I2C2RCV;
}

int     i2c_idle(void)
{
    u8 t = 255;

    while ((I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RCEN || I2C1CONbits.RSEN
            || I2C1CONbits.RSEN || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT) && t--);
    return (1);
}

int     i2c_sendByte(u8 data)
{
    i2c_idle();
    I2C1TRN = data;
    i2c_idle();
    return (1);
}

int     i2c_start(void)
{
    i2c_idle();
    I2C1CONbits.SEN = 1;
    return (1);
}

int     i2c_stop(void)
{
    i2c_idle();
    I2C1CONbits.PEN = 1;
    return (1);
}
*/