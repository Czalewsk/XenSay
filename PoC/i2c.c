/* 
 * File:   i2c.c
 * Author: bocal
 *
 * Created on May 25, 2017, 4:01 AM
 */

#include "XenSay.h"

// Interrupt I2C priority > All || (I2C Priority == Priority (Switch)) > ALL ?

void    i2c_init(void)
{
    u8      tmp = 0;
    u8      i = 0;

//    TRISFbits.TRISF5 = 0;
//    LATFbits.LATF5 = 0;
//   /* while (i++ < 18)                      //Replace this by (If SDA is LOW -> Sends 9 clock pulse)
//    {
//        LATFbits.LATF5 = !LATFbits.LATF5;
//        cpt = 0;
//        while (cpt++ < 2000);
//    }*/
//    TRISFbits.TRISF4 = 0;
//    LATFbits.LATF4 = 0;
    I2C2CON = 0;
    I2C2BRG = 7;
    I2C2STAT = 0;
    I2C2CONbits.SIDL = 1;
    I2C2ADD = ADDR;
    I2C2CONbits.ON = 1;
    tmp = I2C2RCV;
}

int     i2c_idle(void)
{
    u8 t = 255;

    while ((I2C2CONbits.SEN || I2C2CONbits.PEN || I2C2CONbits.RCEN || I2C2CONbits.RSEN
            || I2C2CONbits.RSEN || I2C2CONbits.ACKEN || I2C2STATbits.TRSTAT) || t--);
    return (1);
}

int     i2c_sendByte(u8 data)
{
    i2c_idle();
    I2C2TRN = data;
    i2c_idle();
    return (1);
}

int     i2c_start(void)
{
    i2c_idle();
    I2C2CONbits.SEN = 1;
    return (1);
}

int     i2c_stop(void)
{
    i2c_idle();
    I2C2CONbits.PEN = 1;
    return (1);
}