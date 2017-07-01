#include "XenSay.h"
#include "events.h"

static u32 g_press;    // switch venant d'etre appuye
static u32 g_release;  // swith venant d'etre relache

static void (*onPressCallback)(u32 button);
static void (*onReleaseCallback)(u32 button);

void     init_load_latch(void)
{
    TRISDbits.TRISD0 = 0;
    LATDbits.LATD0 = 0;
    TRISDbits.TRISD1 = 0;
    LATDbits.LATD1 = 1;
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

    actual_state = SPI1BUF;
    g_switch = actual_state;
    g_release = before & ~actual_state; // calcul des switch relaches
    g_press = actual_state & ~before;   // calcul des switch appuyes
    if (g_press  > 0 || g_release > 0)
        switcher();
    event_clearFlag(FLAG_SHIFTREGISTER);
}

void       __attribute__ ((interrupt(IPL6AUTO))) __attribute__ ((vector(23))) spi_interrupt(void)
  {
    if  (SPI1STATbits.SPIROV || IFS0bits.SPI1EIF) // En cas d'erreur
    {
        SPI1STATCLR = 1 << 6;
        event_setFlag(FLAG_SHIFTREGISTER);
        IFS0bits.SPI1EIF = 0;
    }
    if (IFS0bits.SPI1TXIF) // Interrupt quand le registre d'envoi est vide
    {
        pulse_latch();         //Latch les donnees
        IFS0bits.SPI1TXIF = 0; // Remet a 0 le flag d'interrupt
    }
    if (IFS0bits.SPI1RXIF) // Interrup quand le registre de reception est plein
    {
        event_setFlag(FLAG_SHIFTREGISTER);
        IFS0bits.SPI1RXIF = 0;
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