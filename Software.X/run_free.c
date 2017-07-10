#include "XenSay.h"
#include "events.h"
#include "button.h"
#include "audio.h"
#include "led.h"

static u32  last_button_sound;
static u8   octave;


// Foret de if avec poc
// Faire un tableau associatif pour les 3 shift avec decallage binaire pour enlever les if
static void onPressButton(u32 button)
{
    u8 i;
    
    if (button & BTN_CFG_5)
    {
        g_led = 0x0;
        audio_stop();
        audio_setBuzzer(1);
        event_setState(CONFIG);
        return ;
    }
    if (button & BTN_CFG_2)
    {
        octave = octave == 8 ? 8 : octave + 1;
        lcd_write_line("\177   Octave:    \176", 1);
        lcd_write_nb(octave, 1, 12);
    }
    else if (button & BTN_CFG_1)
    {
        octave = octave == 1 ? 1 : octave - 1;
        lcd_write_line("\177   Octave:    \176", 1);
        lcd_write_nb(octave, 1, 12);
    }
    else if (button & BTN_CFG_4)
    {
        audio_setBuzzer(!audio_getBuzzer());
        lcd_write_case(audio_getBuzzer() ? "yes" : "no ", 0, 10);
    }
    
    for (i = 0; i < 13; ++i)
    {
        if (tabBtn[i] & button)
        {
            g_led = tabLed[i];
            last_button_sound = button;
            audio_play(((octave - 1) * 12) + i);
            break;
        }
    }
}

static void onReleaseButton(u32 button)
{
    if (button & last_button_sound)
    {
        audio_stop();
        g_led = 0x0;
    }
}

void run_free(void)
{
    octave = 4;
    setOnPressCallback(&onPressButton);
    setOnReleaseCallback(&onReleaseButton);
    lcd_write_line("  Buzzer: ", 0);
    lcd_write_case(audio_getBuzzer() ? "yes" : "no ", 0, 10);
    lcd_write_line("\177   Octave:    \176", 1);
    lcd_write_nb(octave, 1, 12);
}