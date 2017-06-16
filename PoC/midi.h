/* 
 * File:   midi.h
 * Author: bocal
 *
 * Created on May 18, 2017, 7:15 AM
 */

#ifndef MIDI_H
#define	MIDI_H

#include "types.h"

#define MIDI_BUFFER_SIZE 16

void midi_init();
void midi_play(u8 note);
void midi_stop();

#endif	/* MIDI_H */

