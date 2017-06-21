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

typedef enum {
    START,
    ADDRESS,
    SEND_DATA,
    STOP,
    END,
} I2C_STATES;

typedef struct  t_I2Cdata //I2C data struct with buf
{
    char        data[100];
    u8          len;
    u8          index;
    I2C_STATES  state;
}               s_I2Cdata;

typedef enum  {
    BUSY,
    FREE,
} I2C_BUSY_FLAG;

// State enum
typedef enum {
    CONFIG,
    SIMON,
    LEARN,
    FREE
} G_STATES;

// Global
G_STATES  g_state;    //  etat general dans lequel se trouve le piano
u32     g_led;      //  gestion des leds
u32     g_switch;   // Etat des switch

#endif	/* XENSAY_H */

a