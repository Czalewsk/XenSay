#include <xc.h>
#include <sys/attribs.h>
#include "audio.h"
#include "buzzer.h"
#include "midi.h"
#include "music.h"

static u8 enableMidi;

/*
 * Public function
 */

void audio_init()
{
    enableMidi = 1;

    buzzer_init();
    midi_init();
    //music_init();
}

void audio_play(u8 note)
{
    if (enableMidi)
        midi_play(note);
    buzzer_play(note);
}

void audio_stop()
{
    midi_stop();
    buzzer_stop();
}

void audio_enableMidi()
{
    enableMidi = 1;
}

void audio_disableMidi()
{
    enableMidi = 0;
}