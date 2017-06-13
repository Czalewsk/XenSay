/* 
 * File:   XenSay.h
 * Author: bocal
 *
 * Created on May 19, 2017, 10:19 AM
 */

#ifndef XENSAY_H
#define	XENSAY_H

#include <xc.h>
#include <sys/attribs.h>

//Typedef Unsigned and Signed 8/16/32
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

// I2C Slave ADDR

# define ADDR (0x7C)

// Global
u32 g_press;    // switch venant d'etre appuye
u32 g_release;  // swith venant d'etre relache
STATES  g_state;    //  etat general dans lequel se trouve le piano
u32 g_led;      //  gestion des leds

// State enum
typedef enum {
    INIT;
    SIMON;
    LEARNING;
    FREE;
} STATES;

#endif	/* XENSAY_H */

