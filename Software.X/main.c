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
}

int     main(void)
{
    u32 t = 250000;

    init_interrupt();
    //event_init();
    shiftRegister_init();
    //lcd_init_rst();
    //i2c1_init();
    //lcd_init();
    spi_init();
    //lcd_create_char();
    //init_timer1();
    //audio_init();
    //audio_play(1);
    //timer5_init();
    //timer4_init();
    //while (t--);
    //lcd_init_end();
    //sdcard_init();
    //g_led = 0xffffffff;
    
    while (1)
    {
        //event_update();
        WDTCONbits.WDTCLR = 1;  // Clear le watchdog timer
    }
    return (1);
}
