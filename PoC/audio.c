#include <xc.h>
#include <sys/attribs.h>
#include "audio.h"
#include "buzzer.h"
#include "midi.h"
#include "music.h"

/*
 * Public function
 */

void audio_init()
{
    buzzer_init();
    midi_init();
    music_init();
    audio_play(AUDIO_NOTE_C1);
}

void audio_play(u8 note)
{
    midi_play(note);
    buzzer_play(note);
}

void audio_stop()
{
    midi_stop();
    buzzer_stop();
}