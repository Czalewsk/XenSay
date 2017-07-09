#include "XenSay.h"

static void (*timer5_f)(void);

void    timer5_init(void)
{
    T5CON = 0;              // Reset le registre du timer 1
    T5CONbits.TCKPS = 5;    // Prescale de la clock du timer 1 a 1:64
    IPC5bits.T5IP = 2;      // Set la priorite de l'interruption du timer 1 a 6
    IFS0bits.T5IF = 0;      // Reset du flag d'interrupt du timer 1
    TMR5 = 0;               // Reset le timer 1
    PR5 = 100;            // osc (8 MHz) / PBDIV(8) -> 1MHz ->  / timer prescale(64) -> 15625 -> 1s
    IEC0bits.T5IE = 1;      // Active l'interruption du timer 1
    T5CONbits.ON = 0;
}

void __attribute__ ((interrupt(IPL5AUTO))) __attribute__ ((vector(20))) timer5(void)
{
    if (timer5_f)
        timer5_f();
     TMR5 = 0;
     IFS0bits.T5IF = 0;
}

void    setTimer5F(void (*f)(void), u32 time, u8 tckps, u8 intrrpt)
{
    T5CONbits.ON = 0;
    timer5_f = f;
    PR5 = time;
    IEC0bits.T5IE = intrrpt;
    T5CONbits.TCKPS = tckps;
    TMR5 = 0;
    T5CONbits.ON = 1;
}

void    timer5Off(void)
{
    T5CONbits.ON = 0;
    TMR5 = 0;
}