#include "XenSay.h"

void    initialize_interrupt(void)
{
    INTCONbits.MVEC = 1;             // Set le mode d'interruption multi-vector
    __builtin_enable_interrupts();   // Indique au cpu d'ecouter les interruptions
}

int     main(void)
{
    init_load_latch();
    lcd_init_rst();
    i2c_init();
    spi_init();
    lcd_init();
    lcd_init();
    lcd_create_char();
    initialize_interrupt();
    init_timer1();
    while (1)
    {
        //EVENT_GENERATOR
        //SWITCH_GAME -> GAME MODE...
        //EVENT_CLR
    };
}