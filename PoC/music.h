/* 
 * File:   music.h
 * Author: bocal
 *
 * Created on May 16, 2017, 7:09 AM
 */

#ifndef MUSIC_H
#define	MUSIC_H

#include "types.h"

#define MUSIC_STATE_AUTO_PLAY 0
#define MUSIC_STATE_AUTO_DELAY 1
#define MUSIC_STATE_GAME_WAIT 2

void music_init();
void music_play(u8 *data, u16 length);
void music_stop();
void music_game_start(u8 *data, u16 length, u8 level);
void music_game_note_press(u8 note);

#endif	/* MUSIC_H */

