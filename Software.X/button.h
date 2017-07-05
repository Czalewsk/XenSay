/* 
 * File:   button.h
 * Author: bocal
 *
 * Created on June 17, 2017, 6:27 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#define BTN_CFG_1 0x1000
#define BTN_CFG_2 0x800
#define BTN_CFG_3 0x400
#define BTN_CFG_4 0x200
#define BTN_CFG_5 0x100

#define BTN_NOTE1 0x1000000
#define BTN_NOTE2 0x10000
#define BTN_NOTE3 0x2000000
#define BTN_NOTE4 0x20000
#define BTN_NOTE5 0x4000000
#define BTN_NOTE6 0x8000000
#define BTN_NOTE7 0x40000
#define BTN_NOTE8 0x10000000
#define BTN_NOTE9 0x80000
#define BTN_NOTE10 0x20000000
#define BTN_NOTE11 0x100000
#define BTN_NOTE12 0x40000000
#define BTN_NOTE13 0x80000000

void setOnPressCallback(void (*c)(u32 button));
void setOnReleaseCallback(void (*c)(u32 button));

#endif	/* BUTTON_H */