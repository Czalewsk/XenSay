/* 
 * File:   audio.h
 * Author: bocal
 *
 * Created on May 13, 2017, 8:22 AM
 */

#ifndef AUDIO_H
#define	AUDIO_H

#include "types.h"

#define AUDIO_NOTE_C1  0
#define AUDIO_NOTE_CS1 1
#define AUDIO_NOTE_D1  2
#define AUDIO_NOTE_DS1 3
#define AUDIO_NOTE_E1  4
#define AUDIO_NOTE_F1  5
#define AUDIO_NOTE_FS1 6
#define AUDIO_NOTE_G1  7
#define AUDIO_NOTE_GS1 8
#define AUDIO_NOTE_A1  9
#define AUDIO_NOTE_AS1 10
#define AUDIO_NOTE_B1  11
#define AUDIO_NOTE_C2  12
#define AUDIO_NOTE_CS2 13
#define AUDIO_NOTE_D2  14
#define AUDIO_NOTE_DS2 15
#define AUDIO_NOTE_E2  16
#define AUDIO_NOTE_F2  17
#define AUDIO_NOTE_FS2 18
#define AUDIO_NOTE_G2  19
#define AUDIO_NOTE_GS2 20
#define AUDIO_NOTE_A2  21
#define AUDIO_NOTE_AS2 22
#define AUDIO_NOTE_B2  23
#define AUDIO_NOTE_C3  24
#define AUDIO_NOTE_CS3 25
#define AUDIO_NOTE_D3  26
#define AUDIO_NOTE_DS3 27
#define AUDIO_NOTE_E3  28
#define AUDIO_NOTE_F3  29
#define AUDIO_NOTE_FS3 30
#define AUDIO_NOTE_G3  31
#define AUDIO_NOTE_GS3 32
#define AUDIO_NOTE_A3  33
#define AUDIO_NOTE_AS3 34
#define AUDIO_NOTE_B3  35
#define AUDIO_NOTE_C4  36
#define AUDIO_NOTE_CS4 37
#define AUDIO_NOTE_D4  38
#define AUDIO_NOTE_DS4 39
#define AUDIO_NOTE_E4  40
#define AUDIO_NOTE_F4  41
#define AUDIO_NOTE_FS4 42
#define AUDIO_NOTE_G4  43
#define AUDIO_NOTE_GS4 44
#define AUDIO_NOTE_A4  45
#define AUDIO_NOTE_AS4 46
#define AUDIO_NOTE_B4  47
#define AUDIO_NOTE_C5  48
#define AUDIO_NOTE_CS5 49
#define AUDIO_NOTE_D5  50
#define AUDIO_NOTE_DS5 51
#define AUDIO_NOTE_E5  52
#define AUDIO_NOTE_F5  53
#define AUDIO_NOTE_FS5 54
#define AUDIO_NOTE_G5  55
#define AUDIO_NOTE_GS5 56
#define AUDIO_NOTE_A5  57
#define AUDIO_NOTE_AS5 58
#define AUDIO_NOTE_B5  59
#define AUDIO_NOTE_C6  60
#define AUDIO_NOTE_CS6 61
#define AUDIO_NOTE_D6  62
#define AUDIO_NOTE_DS6 63
#define AUDIO_NOTE_E6  64
#define AUDIO_NOTE_F6  65
#define AUDIO_NOTE_FS6 66
#define AUDIO_NOTE_G6  67
#define AUDIO_NOTE_GS6 68
#define AUDIO_NOTE_A6  69
#define AUDIO_NOTE_AS6 70
#define AUDIO_NOTE_B6  71
#define AUDIO_NOTE_C7  72
#define AUDIO_NOTE_CS7 73
#define AUDIO_NOTE_D7  74
#define AUDIO_NOTE_DS7 75
#define AUDIO_NOTE_E7  76
#define AUDIO_NOTE_F7  77
#define AUDIO_NOTE_FS7 78
#define AUDIO_NOTE_G7  79
#define AUDIO_NOTE_GS7 80
#define AUDIO_NOTE_A7  81
#define AUDIO_NOTE_AS7 82
#define AUDIO_NOTE_B7  83
#define AUDIO_NOTE_C8  84
#define AUDIO_NOTE_CS8 85
#define AUDIO_NOTE_D8  86
#define AUDIO_NOTE_DS8 87
#define AUDIO_NOTE_E8  88
#define AUDIO_NOTE_F8  89
#define AUDIO_NOTE_FS8 90
#define AUDIO_NOTE_G8  91
#define AUDIO_NOTE_GS8 92
#define AUDIO_NOTE_A8  93
#define AUDIO_NOTE_AS8 94
#define AUDIO_NOTE_B8  95
#define AUDIO_NOTE_C9  96

void audio_init();
void audio_play(u8 note);
void audio_stop();
void audio_setMidi(u8 status);
u8   audio_getMidi(void);
void audio_setBuzzer(u8 status);
u8   audio_getBuzzer(void);

#endif	/* AUDIO_H */

