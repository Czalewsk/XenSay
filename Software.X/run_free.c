#include "XenSay.h"
#include "events.h"
#include "button.h"
#include "audio.h"
#include "led.h"

static u32 tabBtn[] = {
    BTN_NOTE1, BTN_NOTE2, BTN_NOTE3, BTN_NOTE4, BTN_NOTE5, BTN_NOTE6, BTN_NOTE7,
    BTN_NOTE8, BTN_NOTE9, BTN_NOTE10, BTN_NOTE11, BTN_NOTE12, BTN_NOTE13
};
static u32 tabLed[] = {
    LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7,
    LED_8, LED_9, LED_10, LED_11, LED_12, LED_13
};

// Foret de if avec poc
// Faire un tableau associatif pour les 3 shift avec decallage binaire pour enlever les if
static void onPressButton(u32 button)
{
    u8 i;
    
    if (button & BTN_CFG_5)
    {
        event_setState(CONFIG);
        return ;
    }
    
    for (i = 0; i < 13; ++i)
    {
        if (tabBtn[i] & button)
        {
            g_led = tabLed[i];
            //audio_play(AUDIO_NOTE_C4 + i);
        }
    }
}

static void onReleaseButton(u32 button)
{
    //audio_stop();
    g_led = 0x0;
}

void run_free(void)
{
    setOnPressCallback(&onPressButton);
    setOnReleaseCallback(&onReleaseButton);
    lcd_write_line("  Playing Free  ", 0);
    lcd_clear_line(1);
}