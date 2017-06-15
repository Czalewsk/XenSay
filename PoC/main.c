#include "XenSay.h"
#include "audio.h"

void run_config(void);
void run_simon(void);
void run_learning(void);
void run_free(void);

void    init_interrupt(void)
{
    INTCONbits.MVEC = 1;             // Set le mode d'interruption multi-vector
    __builtin_enable_interrupts();   // Indique au cpu d'ecouter les interruptions
}

void    init_global(void)
{
    g_state = CONFIG;
    g_led = 0xFF;
}

int     main(void)
{
    init_global();
    init_load_latch();
    lcd_init_rst();
    i2c_init();
    spi_init();
    lcd_init();
    lcd_create_char();
    init_interrupt();
    init_timer1();
	audio_init();
    while (1)
    {
        //EVENT_GENERATOR
        //SWITCH_GAME -> GAME MODE...
        //EVENT_CLR
        
/*        switch(g_state)
        {
            case CONFIG:
                run_config();
                break;
            case SIMON:
                run_simon();
                break;
            case LEARNING:
                run_learning();
                break;
            case FREE:
                run_free();
                break;
        }*/
		WDTCONbits.WDTCLR = 1;  // Clear le watchdog timer
    }
    return (1);
}
