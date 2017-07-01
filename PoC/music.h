/* 
 * File:   music.h
 * Author: bocal
 *
 * Created on May 16, 2017, 7:09 AM
 */

#ifndef MUSIC_H
#define	MUSIC_H

#include "types.h"

#define FLAG_PLAY 1
#define FLAG_DELAY 2
#define FLAG_AUTO 8

void    music_init();
void    music_play(u8 *data, u16 length);
void    music_stop();
void    music_startStep(u8 *data, u16 length);
void    music_playStep();
u8      music_getStepNote();
u8      music_getStepLength();
u8      music_getStepDelay();
void    music_setOnStepEnd(void (*c)(void));

#endif	/* MUSIC_H */

