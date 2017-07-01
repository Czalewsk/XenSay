#include "XenSay.h"
#include "events.h"

static u32 g_press;    // switch venant d'etre appuye
static u32 g_release;  // swith venant d'etre relache

static void (*onPressCallback)(u32 button);
static void (*onReleaseCallback)(u32 button);

void     shiftRegister_init(void)
{
    TRISBbits.TRISB4 = 0; // Latch
    LATBbits.LATB4 = 0;
    TRISBbits.TRISB10 = 0; // Load
    LATBbits.LATB10 = 1;
}

void    pulse_load(void)
{
    LATBbits.LATB10 = 0;
    LATBbits.LATB10 = 1;
}

void    pulse_latch(void)
{
    LATBbits.LATB4 = 1;
    LATBbits.LATB4 = 0;
}

static void switcher(void)
{
	if (g_press > 0 && onPressCallback)
		onPressCallback(g_press);
	if (g_release > 0 && onReleaseCallback)
		onReleaseCallback(g_release);
}

void sr_flag_update(void)
{
    static u32 before;
    static u32 actual_state;

    before = actual_state;

    actual_state = SPI1BUF & 0xFFFFFF00;
    IEC1bits.SPI1RXIE = 1;
    g_switch = actual_state;
    g_release = before & ~actual_state; // calcul des switch relaches
    g_press = actual_state & ~before;   // calcul des switch appuyes
    if (g_press  > 0 || g_release > 0)
        switcher();
    event_clearFlag(FLAG_SHIFTREGISTER);
}

void       __attribute__ ((interrupt(IPL6AUTO))) __attribute__ ((vector(31))) spi_interrupt(void)
  {
    if  (SPI1STATbits.SPIROV || IFS1bits.SPI1EIF) // En cas d'erreur
    {
        SPI1STATCLR = 1 << 6;
//        event_setFlag(FLAG_SHIFTREGISTER);
//        IEC1bits.SPI1RXIE = 1;
//        IFS1bits.SPI1EIF = 0;
    }
    if (IFS1bits.SPI1TXIF) // Interrupt quand le registre d'envoi est vide
    {
        IEC1bits.SPI1TXIE = 0;
        pulse_latch();         //Latch les donnees
        IFS1bits.SPI1TXIF = 0; // Remet a 0 le flag d'interrupt
    }
    if (IFS1bits.SPI1RXIF) // Interrup quand le registre de reception est plein
    {
        event_setFlag(FLAG_SHIFTREGISTER);
        IEC1bits.SPI1RXIE = 0;
        IFS1bits.SPI1RXIF = 0;
    }
}

void setOnPressCallback(void (*c)(u32 button))
{
	onPressCallback = c;
}

void setOnReleaseCallback(void (*c)(u32 button))
{
	onReleaseCallback = c;
}