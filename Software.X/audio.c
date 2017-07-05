#include <xc.h>
#include <sys/attribs.h>
#include "audio.h"
#include "buzzer.h"
#include "midi.h"
#include "music.h"

static u8 enableMidi;
static u8 enableBuzzer;

/*
 * Public function
 */

void audio_init()
{
    enableMidi = 1;
    enableBuzzer = 1;

    buzzer_init();
    midi_init();
    music_init();
}

void audio_play(u8 note)
{
    if (enableMidi)
        midi_play(note);
    if (enableBuzzer)
        buzzer_play(note);
}

void audio_stop()
{
    midi_stop();
    buzzer_stop();
}

void audio_setMidi(u8 status)
{
    enableMidi = status;
}

u8  audio_getMidi(void)
{
    return (enableMidi);
}

void audio_setBuzzer(u8 status)
{
    enableBuzzer = status;
}

u8  audio_getBuzzer(void)
{
    return (enableBuzzer);
}