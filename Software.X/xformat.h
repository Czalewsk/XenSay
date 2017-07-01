/* 
 * File:   xformat.h
 * Author: Tim
 *
 * Created on June 28, 2017, 7:46 AM
 */

#ifndef XFORMAT_H
#define	XFORMAT_H

#include "types.h"

#define XFORMAT_VERSION 1
#define XFORMAT_FAT_MAXENTRY 64
#define XFORMAT_FAT_ENTRYSIZE 64
#define XFORMAT_FAT_ENTRYINSECTOR 8
#define XFORMAT_MUSIC_MAXNAME 60
#define XFORMAT_MUSIC_MAXSIZE 2048

// WTF MACRO XD PTR LOOOOOOL Tell tim if you want morealloc
// FAT access Macros
#define GET_FATENTRYSIZE(block, entry) ((u16)block[((entry % XFORMAT_FAT_ENTRYINSECTOR)\
    * XFORMAT_FAT_ENTRYSIZE) + 2]) << 8 | block[((entry % XFORMAT_FAT_ENTRYINSECTOR) * \
    XFORMAT_FAT_ENTRYSIZE) + 3]

#define GET_FATENTRYSECTOR(block, entry) ((u16)block[((entry % XFORMAT_FAT_ENTRYINSECTOR)\
    * XFORMAT_FAT_ENTRYSIZE)]) << 8 | block[((entry % XFORMAT_FAT_ENTRYINSECTOR) * \
    XFORMAT_FAT_ENTRYSIZE) + 1]

u8 xformat_start();
u8 xformat_isFormatted();

/* Music functions can retrieve music informations in FAT and load the data
 * - You must first call xformat_firstMusic to init
 * - firstMusic() return null if no music in sdcard
 * - musicNext() & prev() return the same name if no music at next/prev
 * - firstMusic(), next(), prev() return the name of current music
 * - loadMusic() return array of data
 */

u8 *xformat_firstMusic();
u8 *xformat_nextMusic();
u8 *xformat_prevMusic();
u8 *xformat_loadMusic();
u16 xformat_sizeMusic();
u8 *xformat_nameMusic();
u8 *xformat_dataMusic();

#endif	/* XFORMAT_H */

