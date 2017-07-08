#include "XenSay.h"
#include "events.h"
#include "button.h"
#include "correspondances.h"
#include "audio.h"
#include "buzzer.h"
#include "midi.h"
#include "music.h"

void    run_simon(void);

typedef enum    {
    INIT,
    DIFFICULTY,
    INIT_PLAY,
    PLAY,
    LOOSE,
    WIN,
    EXIT,
} SIMON_STATES;

typedef enum    {
    BLINK_ON,
    BLINK_OFF,
    BLINK_DELAY,
    BLINK_PATTERN,
}   BLINK_STATES;

static  u32      corr_btn[13] = {BTN_NOTE1, BTN_NOTE3, BTN_NOTE5, BTN_NOTE6,
                                BTN_NOTE8, BTN_NOTE10, BTN_NOTE12, BTN_NOTE13,
                                BTN_NOTE2, BTN_NOTE4, BTN_NOTE7, BTN_NOTE9,
                                BTN_NOTE11};

static  SIMON_STATES   simon_state = INIT;
static  u32            pattern[100]; // Pattern Simon
static  u32            len_pattern;        // Len of simon
static  u8             show_pattern;  // affichage du pattern
static  u8             in_game;
static  u8             simon_index;
static  u8             simon_modulo;
static  u32            simon_pr;
static  u8             decalage_difficulty;
static  BLINK_STATES   blink = BLINK_ON;
static  u8             disable_state_buzzer;

static  u32            simon_difficulty_time[2] = {30000, 10000};
static  u8             simon_difficulty_btn[6] = {2, 4, 6, 13, 8, 13};

void    exit_simon(void)
{
    audio_stop();
    audio_setBuzzer(1);
    timer4Off();
    timer5Off();
    g_led = 0;
    simon_state = INIT;
    event_setState(CONFIG);
}

void    reinit_simon(u32 button)
{
    timer4Off();
    simon_state = INIT;
    event_setFlag(FLAG_SIMON);
}

static void simon_sound_off(u32 button)
{
    if (in_game)
        audio_stop();
}

void simon_sound_toggle(void)  //Set l'etatdu buzzer On <-> Off
{
    static  u8  state;

    audio_setBuzzer(state);
    lcd_write_line(" Sound = ", 0);
    if (state)
        lcd_write_case("On     ", 0, 9);
    else
        lcd_write_case("Off    ", 0, 9);
    state = !state;
    disable_state_buzzer = 1;
}

void    play_note_simon(u32 button, u8 octave)
{
    u8  tab_correspondance[] = { 0, 2, 4, 5, 7, 9, 11, 12, 1, 3 ,6, 8, 10};

     audio_play(((octave - 1) * 12) + tab_correspondance[button]);
}

void    blink_mode(u8 *index)
{
    switch (blink)
    {       
        case(BLINK_ON):
             g_led = 0;
             audio_stop();
             PR4 = 35000;
             blink = BLINK_OFF;
             break;
        case(BLINK_OFF):
            g_led = 1 << pattern[(*index)];
            PR4 = simon_pr;
            audio_stop();
            play_note_simon(pattern[(*index)++], 4);
            blink = BLINK_ON;
            break;
        case(BLINK_DELAY):
            //audio_stop();
            in_game = 0;
            PR4 = 20000;
            blink = BLINK_PATTERN;
            break;
        case(BLINK_PATTERN):
            in_game = 0;
            g_led = 0;
            audio_stop();
            PR4 = 35000;
            blink = BLINK_OFF;
            break;
    }       
}

void    light_pattern(void)
{
    static  u8  i;

    if (!show_pattern)
        return ;
    if (i >= len_pattern)
    {
        g_led = 0;
        audio_stop();
        show_pattern = 0;
        in_game = 1;
        timer4Off();
        blink = BLINK_ON;
        i = 0;
        return ;
    }
    simon_sound_off(0);
    blink_mode(&i);
}

void    difficulty_simon(u32 button)
{
    static u8  i = 0;

    char    tab[6][15] = {
        "      TIM     ",
        "     EASY     ",
        "    NORMAL    ",
        "     HARD     ",
        "    EXTREME   ",
        "     CAROL    ",
    };

    if (button & BTN_CFG_5)
    {
        exit_simon();
        return ;
    }
    if (disable_state_buzzer)
    {
        lcd_write_line(" Set Difficulty  ", 0);
        disable_state_buzzer = 0;
    }
    if (button & BTN_CFG_4)
    {
        simon_sound_toggle();
        return ;
    }
    if (button & BTN_CFG_3)
    {
        simon_modulo = simon_difficulty_btn[i];
        decalage_difficulty = (i <= 2) ? (3 - i): 0;  // decalage des boutons et les leds au centre du clavier dans le mode TIM, EASY et NORMAL
        simon_pr = simon_difficulty_time[i / 4];
        pattern[len_pattern++] = (TMR5 % simon_modulo) + decalage_difficulty;
        setTimer4F(&light_pattern, simon_pr, 4);
        simon_state = INIT_PLAY;
        event_setFlag(FLAG_SIMON);
        return ;
    }
    else if (button & BTN_CFG_2)
        i = (i == 5) ? 0 : i + 1;
    else if (button & BTN_CFG_1)
        i = (i == 0) ? 5 : i - 1;
    lcd_write_case(tab[i], 1, 1);
}

void    play_simon(u32 button)
{
    if (button & BTN_CFG_5)
    {
        exit_simon();
        return ;
    }
    if (button & BTN_CFG_4)
    {
        simon_sound_toggle();
        return ;
    }
    if (in_game == 1)
    {
        if (button & corr_btn[pattern[simon_index]])
        {
            play_note_simon(pattern[simon_index], 4);
            g_led = 1 << pattern[simon_index];
            simon_index++;
        }
        else
        {
            play_note_simon(3, 1);
            simon_state = LOOSE;
            event_setFlag(FLAG_SIMON);
            return ;
        }
        if (simon_index >= len_pattern)
        {
            simon_index = 0;
            timer4On();
            blink = BLINK_DELAY;
            event_setFlag(FLAG_SIMON);
            return ;
        }
    }
    return ;
}

void    run_simon(void)
{
    switch(simon_state)
    {
            case(INIT):
                simon_sound_off(0);
                timer5Off();
                setTimer5F(NULL, 65000, 7, 0);
                g_led = 0;
                len_pattern = 0;
                show_pattern = 0;
                simon_index = 0;
                in_game = 0;
                simon_modulo = 0;
                simon_pr = 0;
                simon_state = DIFFICULTY;
            case(DIFFICULTY):
                lcd_write_line(" Set Difficulty  ", 0);
                lcd_write_line("\177              \176", 1);
                difficulty_simon(0);
                setOnPressCallback(&difficulty_simon);
                break ;
            case(INIT_PLAY):
                lcd_clear();
                lcd_write_line("  Let's Play !  ", 0);
                lcd_write_line("Your score is   ", 1);
                setOnPressCallback(&play_simon);
                setOnReleaseCallback(&simon_sound_off);
                simon_state = PLAY;
            case(PLAY):
                if (disable_state_buzzer)
                {
                    lcd_write_line("  Let's Play !  ", 0);
                    disable_state_buzzer = 0;
                }
                pattern[len_pattern++] = (TMR5 % simon_modulo) + decalage_difficulty;
                lcd_write_nb(len_pattern > 2 ? len_pattern - 2 : 0, 1, 14);
                show_pattern = 1;
                timer4On();
                blink = BLINK_DELAY;
                break ;
            case(LOOSE):
                g_led = 0xFFFF;
                lcd_clear();
                lcd_write_line("Loose! Try Again", 0);
                lcd_write_line("Your score is   ", 1);
                lcd_write_nb(len_pattern > 2 ? len_pattern - 2 : 0, 1, 14);
                setOnPressCallback(&reinit_simon);
                break ;
    }
    event_clearFlag(FLAG_SIMON);
    return ;
}