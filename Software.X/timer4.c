#include "XenSay.h"

static void (*timer4_f)(void);

void    timer4_init(void)
{
    T4CON = 0;              // Reset le registre du timer 4
    T4CONbits.TCKPS = 5;    // Prescale de la clock du timer 4 a 1:64
    IPC4bits.T4IP = 5;      // Set la priorite de l'interruption du timer 4 a 6
    IFS0bits.T4IF = 0;      // Reset du flag d'interrupt du timer 4
    TMR4 = 0;               // Reset le timer 4
    PR4 = 150;            // osc (8 MHz) / PBDIV(8) -> 1MHz ->  / timer prescale(64) -> 15625 -> 1s
    IEC0bits.T4IE = 1;      // Active l'interruption du timer 4
    T4CONbits.ON = 0;
}

void __attribute__ ((interrupt(IPL5AUTO))) __attribute__ ((vector(16))) timer4(void)
{
    if (timer4_f)
        timer4_f();
     TMR4 = 0;
     IFS0bits.T4IF = 0;
}

void    setTimer4F(void (*f)(void), u32 pr4, u32 tckps)
{
    T4CONbits.ON = 0;
    IFS0bits.T4IF = 0;
    timer4_f = f;
    T4CONbits.TCKPS = tckps;
    PR4 = pr4;
    TMR4 = 0;
    T4CONbits.ON = 1;
}

void    timer4Off(void)
{
    T4CONbits.ON = 0;
    TMR4 = 0;
}