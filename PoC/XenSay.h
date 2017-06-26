/* 
 * File:   XenSay.h
 * Author: bocal
 *
 * Created on May 19, 2017, 10:19 AM
 */

#ifndef XENSAY_H
#define	XENSAY_H

# include <xc.h>
# include <sys/attribs.h>
# include "types.h"

// I2C Slave ADDR
# define ADDR (0x7C)

//LCD Struct
typedef struct  s_lcd
{
    char    buffer[50];
    u8      index;
    u8      len;
    u8      line;
}               t_lcdBuff;

// Global
u32     g_led;      //  gestion des leds
u32     g_switch;   // Etat des switch

#endif	/* XENSAY_H */

