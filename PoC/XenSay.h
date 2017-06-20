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

// Global
u32     g_led;      //  gestion des leds
u32     g_switch;   // Etat des switch

#endif	/* XENSAY_H */

