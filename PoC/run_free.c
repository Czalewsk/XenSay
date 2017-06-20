#include "XenSay.h"
#include "events.h"
#include "button.h"
#include "audio.h"

// Foret de if avec poc
// Faire un tableau associatif pour les 3 shift avec decallage binaire pour enlever les if
static void onPressButton(u32 button)
{
    if (button & BTN_NOTE1)
    {
        audio_play(AUDIO_NOTE_C4);
        g_led = 0x1;
    }
    else if (button & BTN_NOTE2)
    {
        audio_play(AUDIO_NOTE_CS4);
        g_led = 0x2;
    }
    else if (button & BTN_NOTE3)
    {
        audio_play(AUDIO_NOTE_D4);
        g_led = 0x4;
    }
    else if (button & BTN_NOTE4)
    {
        audio_play(AUDIO_NOTE_DS4);
        g_led = 0x8;
    }
    else if (button & BTN_NOTE5)
    {
        audio_play(AUDIO_NOTE_E4);
        g_led = 0x10;
    }
    else if (button & BTN_CFG_1)
        event_setState(CONFIG);
}

static void onReleaseButton(u32 button)
{
    audio_stop();
    g_led = 0x0;
}

void run_free(void)
{
    setOnPressCallback(&onPressButton);
    setOnReleaseCallback(&onReleaseButton);
    lcd_write_line("  Playing Free  ", 0);
    lcd_write_line("                ", 1);
}