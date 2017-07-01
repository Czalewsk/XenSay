/* 
 * File:   buzzer.h
 * Author: bocal
 *
 * Created on May 13, 2017, 12:21 AM
 */

#ifndef BUZZER_H
#define	BUZZER_H

#include "types.h"

#define BUZZER_PERIOD 500000

#define BUZZER_NOTE_C1  32
#define BUZZER_NOTE_CS1 34
#define BUZZER_NOTE_D1  36
#define BUZZER_NOTE_DS1 38
#define BUZZER_NOTE_E1  41
#define BUZZER_NOTE_F1  43
#define BUZZER_NOTE_FS1 46
#define BUZZER_NOTE_G1  49
#define BUZZER_NOTE_GS1 51
#define BUZZER_NOTE_A1  55
#define BUZZER_NOTE_AS1 58
#define BUZZER_NOTE_B1  61
#define BUZZER_NOTE_C2  65
#define BUZZER_NOTE_CS2 69
#define BUZZER_NOTE_D2  73
#define BUZZER_NOTE_DS2 77
#define BUZZER_NOTE_E2  82
#define BUZZER_NOTE_F2  87
#define BUZZER_NOTE_FS2 92
#define BUZZER_NOTE_G2  98
#define BUZZER_NOTE_GS2 103
#define BUZZER_NOTE_A2  110
#define BUZZER_NOTE_AS2 116
#define BUZZER_NOTE_B2  123
#define BUZZER_NOTE_C3  130
#define BUZZER_NOTE_CS3 138
#define BUZZER_NOTE_D3  146
#define BUZZER_NOTE_DS3 155
#define BUZZER_NOTE_E3  164
#define BUZZER_NOTE_F3  174
#define BUZZER_NOTE_FS3 185
#define BUZZER_NOTE_G3  196
#define BUZZER_NOTE_GS3 207
#define BUZZER_NOTE_A3  220
#define BUZZER_NOTE_AS3 233
#define BUZZER_NOTE_B3  246
#define BUZZER_NOTE_C4  261
#define BUZZER_NOTE_CS4 277
#define BUZZER_NOTE_D4  293
#define BUZZER_NOTE_DS4 311
#define BUZZER_NOTE_E4  329
#define BUZZER_NOTE_F4  349
#define BUZZER_NOTE_FS4 369
#define BUZZER_NOTE_G4  392
#define BUZZER_NOTE_GS4 415
#define BUZZER_NOTE_A4  440
#define BUZZER_NOTE_AS4 466
#define BUZZER_NOTE_B4  493
#define BUZZER_NOTE_C5  523
#define BUZZER_NOTE_CS5 554
#define BUZZER_NOTE_D5  587
#define BUZZER_NOTE_DS5 622
#define BUZZER_NOTE_E5  659
#define BUZZER_NOTE_F5  698
#define BUZZER_NOTE_FS5 739
#define BUZZER_NOTE_G5  783
#define BUZZER_NOTE_GS5 830
#define BUZZER_NOTE_A5  880
#define BUZZER_NOTE_AS5 932
#define BUZZER_NOTE_B5  987
#define BUZZER_NOTE_C6  1046
#define BUZZER_NOTE_CS6 1108
#define BUZZER_NOTE_D6  1174
#define BUZZER_NOTE_DS6 1244
#define BUZZER_NOTE_E6  1318
#define BUZZER_NOTE_F6  1396
#define BUZZER_NOTE_FS6 1479
#define BUZZER_NOTE_G6  1567
#define BUZZER_NOTE_GS6 1661
#define BUZZER_NOTE_A6  1760
#define BUZZER_NOTE_AS6 1864
#define BUZZER_NOTE_B6  1975
#define BUZZER_NOTE_C7  2093
#define BUZZER_NOTE_CS7 2217
#define BUZZER_NOTE_D7  2349
#define BUZZER_NOTE_DS7 2489
#define BUZZER_NOTE_E7  2637
#define BUZZER_NOTE_F7  2793
#define BUZZER_NOTE_FS7 2959
#define BUZZER_NOTE_G7  3135
#define BUZZER_NOTE_GS7 3322
#define BUZZER_NOTE_A7  3520
#define BUZZER_NOTE_AS7 3729
#define BUZZER_NOTE_B7  3951
#define BUZZER_NOTE_C8  4186
#define BUZZER_NOTE_CS8 4434
#define BUZZER_NOTE_D8  4698
#define BUZZER_NOTE_DS8 4978
#define BUZZER_NOTE_E8  5274
#define BUZZER_NOTE_F8  5587
#define BUZZER_NOTE_FS8 5919
#define BUZZER_NOTE_G8  6271
#define BUZZER_NOTE_GS8 6644
#define BUZZER_NOTE_A8  7040
#define BUZZER_NOTE_AS8 7458
#define BUZZER_NOTE_B8  7902

void buzzer_init();
void buzzer_play(u8 note);
void buzzer_stop();

#endif	/* BUZZER_H */

