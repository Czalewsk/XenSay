#include <xc.h>
#include <sys/attribs.h>
#include "music.h"
#include "audio.h"

/*
 * Internal variables
 */

static u8 state;
static u8 *music;
static u8 *endmusic;

/*
 * Internal function
 */

static void music_timer_reset()
{
    T3CONbits.ON = 0;
    TMR3 = 0;
    IFS0bits.T3IF = 0;
}

static void music_play_step()
{
    music_timer_reset();
    if (music + 3 > endmusic)
        audio_stop();
    else
    {
        state = MUSIC_STATE_AUTO_PLAY;
        audio_play(*music++ - 1);
        PR3 = (*music++ * 39) + 50;
        TMR3 = 0;
        T3CONbits.ON = 1;
    }
}

/*
 * Public function
 */

void music_init()
{
    music = NULL;

    // Enable interruption timer audio
    IEC0bits.T3IE = 1;
    IPC2bits.T3IP = 5;
    IFS0bits.T3IF = 0;

    // Settings timer audio
    T3CON = 0;
    T3CONbits.TCKPS = 7; // Prescal timer
    T3CONbits.TGATE = 0;
    T3CONbits.ON = 0;
}

// Send length in 100/s
/*void audio_play_until(u16 freq, u16 length)
{
    music = NULL;

    audio_timer_reset();
    buzzer_play(freq);

    PR2 = length * 39;// 3906 = 1s with 256 divide, 39 = 0.001s
    T2CONbits.ON = 1;
}*/

void music_play(u8 *data, u16 length)
{
    music = data;
    endmusic = data + length;
    music_play_step();
}

void music_stop()
{
    music = NULL;
    music_timer_reset();
    audio_stop();
}

/*
 * Game section
 */

static u8 level;
static u8 waitNote;


static void music_game_wait_note(u8 note)
{
    // Enable led
}

static void music_game_timeout()
{

}

static void music_game_step()
{
    if (music + 2 >= endmusic)
    {
        music_stop();
    }
    else
    {
        waitNote = *music++;
        state = MUSIC_STATE_GAME_WAIT;
        music_game_wait_note(waitNote);
        PR3 = ((*music++ * 39) * level) + 50; // Set le timeout
    }
}

// Level = timeout: delay * lvl
void music_game_start(u8 *data, u16 length, u8 lvl)
{
    level = lvl;
    music = data;
    endmusic = data + length - 1;
}

void music_game_note_press(u8 note)
{
    // When button press, check note
    music_timer_reset();
    /*if (note == waitNote)
        //OK
        (void);
    else
        //BAD
        (void);*/
}

/*
 * Interruption
 */

__ISR(_TIMER_3_VECTOR, IPL5AUTO) MusicTimer()
{
    if (state == MUSIC_STATE_AUTO_PLAY)
    {
        state = MUSIC_STATE_AUTO_DELAY;
        audio_stop();
        music_timer_reset();
        PR3 = (*music++ * 39) + 50;
        T3CONbits.ON = 1;
    }
    else if (state == MUSIC_STATE_AUTO_DELAY)
    {
        music_play_step();
    }
    else if (state == MUSIC_STATE_GAME_WAIT)
    {
        music_timer_reset();
        music_game_timeout();
    }
}
