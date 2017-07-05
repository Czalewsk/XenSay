/* 
 * File:   eventgenerator.h
 * Author: bocal
 *
 * Created on June 20, 2017, 2:37 PM
 */

#ifndef EVENTS_H
#define	EVENTS_H

#include "types.h"

// State enum
typedef enum {
    CONFIG,
    SIMON,
    LEARN,
    FREE,
    NOSTATE
} STATES;

// Flags
#define FLAG_SHIFTREGISTER 1
#define FLAG_MIDI 2
#define FLAG_SIMON 4

void event_init();
void event_setState(STATES state);
void event_setFlag(u8 flag);
void event_clearFlag(u8 flag);

#endif	/* EVENTS_H */

