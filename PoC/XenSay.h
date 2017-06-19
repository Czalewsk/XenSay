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

// I2C
# define ADDR (0x7C)  // I2C screen Addr

typedef struct  t_I2Cdata //I2C data struct with buf
{
    char    data[50];
    u8      len;
}               s_I2Cdata;

// State enum
typedef enum {
    CONFIG,
    SIMON,
    LEARN,
    FREE
} STATES;

// Global
STATES  g_state;    //  etat general dans lequel se trouve le piano
u32     g_led;      //  gestion des leds
u32     g_switch;   // Etat des switch

#endif	/* XENSAY_H */

