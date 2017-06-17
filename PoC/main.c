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
    g_led = 0x00;
}

int     main(void)
{
    STATES old_state = -1;

    init_global();
    init_load_latch();
    lcd_init_rst();
    i2c_init();
    lcd_init();
    spi_init();
    lcd_create_char();
    init_interrupt();
    init_timer1();
    lcd_init_end();
    audio_init();
    buzzer_init();
    while (1)
    {
        //EVENT_GENERATOR
        //SWITCH_GAME -> GAME MODE...
        //EVENT_CLR

        if (old_state != g_state)
            switch(g_state)
            {
                case CONFIG:
                {
                    old_state = CONFIG;
                    run_config();
                    break;
                }
    //            case SIMON:
    //            {
    //               old_state = SIMON;
    //               run_simon();
    //               break;
    //            }
    //            case LEARN:
    //            {
    //                old_state = LEARN;
    //                run_learn();
    //                break;
    //            }
    //            case FREE:
    //            {
    //                old_state = FREE;
    //                run_free();
    //                break;
    //            }
                default:
                {
                    old_state = -1;
                    g_state = CONFIG;
                    run_config();
                }
            }
        WDTCONbits.WDTCLR = 1;  // Clear le watchdog timer
    }
    return (1);
}
