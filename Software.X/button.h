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

#define BTN_NOTE1 0x4
#define BTN_NOTE2 0x20
#define BTN_NOTE3 0x2
#define BTN_NOTE4 0x10
#define BTN_NOTE5 0x1
#define BTN_NOTE6 0x0
#define BTN_NOTE7 0x0
#define BTN_NOTE8 0x0
#define BTN_NOTE9 0x0
#define BTN_NOTE10 0x0
#define BTN_NOTE11 0x0
#define BTN_NOTE12 0x0
#define BTN_NOTE13 0x0

void setOnPressCallback(void (*c)(u32 button));
void setOnReleaseCallback(void (*c)(u32 button));

#endif	/* BUTTON_H */