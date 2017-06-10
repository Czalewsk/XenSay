#include "XenSay.h"

void     init_led_latch(void)
{
    TRISDbits.TRISD0 = 0;
    LATDbits.LATD0 = 0;
}

void    pulse_load(void)
{
    LATDbits.LATD1 = 0;
    LATDbits.LATD1 = 1;
}

void    pulse_latch(void)
{
    LATDbits.LATD0 = 1;
    LATDbits.LATD0 = 0;
}

void       __attribute__ ((interrupt(IPL6AUTO))) __attribute__ ((vector(23))) spi_interrupt(void)
{
    if  (SPI1STATbits.SPIROV || IFS0bits.SPI1EIF) // En cas d'erreur
        ;
    if (IFS0bits.SPI1TXIF) // Interrupt quand le registre d'envoi est vide
    {
        pulse_latch();         //Latch les donnees
        IFS0bits.SPI1TXIF = 0; // Remet a 0 le flag d'interrupt
    }
    if (IFS0bits.SPI1RXIF) // Interrup quand le registre de reception est plein
    {
        g_input = SPI1BUF;
        IFS0bits.SPI1RXIF = 0;
    }
}

