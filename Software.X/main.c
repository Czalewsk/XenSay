#include "XenSay.h"
#include "events.h"
#include "audio.h"
#include "sdcard.h"

void run_config(void);
void run_simon(void);
void run_learning(void);
void run_free(void);

void    init_interrupt(void)
{
    INTCONbits.MVEC = 1;             // Set le mode d'interruption multi-vector
    __builtin_enable_interrupts();   // Indique au cpu d'ecouter les interruptions
    ANSELA = 0;
    ANSELB = 0;
}

void    turnOnLED(u32 button)
{
    g_led = ((button & 0x1F0000) >> 8) | (button >> 24) | (((g_switch & 0x1F0000) >> 8) | (g_switch >> 24));
}

void    turnOffLED(u32 button)
{
    g_led = g_led & ~(((button & 0x1F0000) >> 8) | (button >> 24));
}

int     main(void)
{
    u32 t = 95000;

    lcd_init_rst();
    init_interrupt();
    event_init();
    i2c1_init();
    shiftRegister_init();
    spi_init();
    lcd_init();
    lcd_create_char();
    init_timer1();
    audio_init();
    timer5_init();
    timer4_init();
    //while (t--);
    lcd_init_end();
    lcd_clear();
    sdcard_init();
    //setOnPressCallback(&turnOnLED);
    //setOnReleaseCallback(&turnOffLED);
    
    while (1)
    {
        event_update();
        WDTCONbits.WDTCLR = 1;  // Clear le watchdog timer
    }
    return (1);
}
