/* 
 * File:   sdcard.h
 * Author: bocal
 *
 * Created on June 20, 2017, 1:07 PM
 */

#ifndef SDCARD_H
#define	SDCARD_H

#include "types.h"

#define FLAGS_CCS 1

void sdcard_init(void);
u8 sdcard_start(void);
u8 *sdcard_read(u32 addr);

#endif	/* SDCARD_H */

