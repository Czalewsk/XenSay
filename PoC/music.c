#include <xc.h>
#include <sys/attribs.h>
#include "music.h"
#include "audio.h"

/*
 * Internal variables
 */

static u8 fState;
static u8 *music;
static u8 *endmusic;
static void (*onStepEnd)(void);

/*
 * Internal function
 */

static void music_timerReset()
{
    T3CONbits.ON = 0;
    TMR3 = 0;
    IFS0bits.T3IF = 0;
}

/*
 * Public function
 */

void music_init()
{
    music = NULL;

    // Enable interruption timer audio
    IEC0bits.T3IE = 1;
    IPC3bits.T3IP = 5;
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
    fState = FLAG_AUTO;
    music = data;
    endmusic = data + length;
    music_playStep();
}

void music_stop()
{
    music = NULL;
    music_timerReset();
    audio_stop();
}

// Level = timeout: delay * lvl
void music_startStep(u8 *data, u16 length)
{
    fState = 0;
    music = data;
    endmusic = data + length;
    onStepEnd = NULL;
}

void music_playStep()
{
    if (!music)
        return ;
    
    music_timerReset();
    if (music + 3 > endmusic)
        music_stop();
    else
    {
        fState |= FLAG_PLAY;
        audio_play(*music++ - 1);
        PR3 = (*music++ * 39) + 50;
        TMR3 = 0;
        T3CONbits.ON = 1;
    }
}

u8 music_getStepNote()
{
    if (!music || music + 3 > endmusic)
        return (0);
    return (*music);
}

u8 music_getStepLength()
{
    if (!music || music + 3 > endmusic)
        return (0);
    return (*(music + 1) * 39);
}

u8 music_getStepDelay()
{
    if (!music || music + 3 > endmusic)
        return (0);
    return (*(music + 2) * 39);
}

void music_setOnStepEnd(void (*c)(void))
{
    onStepEnd = c;
}

/*
 * Interruption
 */

__ISR(_TIMER_3_VECTOR, IPL5AUTO) MusicTimer()
{
    if (fState & FLAG_PLAY)
    {
        fState ^= (FLAG_PLAY | FLAG_DELAY);
        audio_stop();
        music_timerReset();
        PR3 = (*music++ * 39) + 50;
        T3CONbits.ON = 1;
    }
    else if (fState & FLAG_DELAY)
    {
        fState &= ~FLAG_DELAY;
        
        if (fState & FLAG_AUTO)
            music_playStep();
        else
        {
            audio_stop();
            music_timerReset();
            if (onStepEnd)
                onStepEnd();
        }
    }
}
