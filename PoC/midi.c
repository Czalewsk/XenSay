#include <xc.h>
#include <sys/attribs.h>
#include "midi.h"

static u8 currentNote;
static u8 buffer[MIDI_BUFFER_SIZE];
static u8 bufferIndex;

static void midi_send_buffer()
{
    u8 i = 0;

    while (i < bufferIndex && !U2STAbits.UTXBF)
        U2TXREG = buffer[--bufferIndex];
}

static void midi_add_buffer(u8 byte)
{
    if (bufferIndex < MIDI_BUFFER_SIZE)
    {
        u8 i = bufferIndex;

        while (i > 0)
            buffer[i] = buffer[--i];

        buffer[0] = byte;
        ++bufferIndex;
    }
}

static void midi_note_on(u8 midiNote)
{
    midi_add_buffer(0b10010000); // Status byte
    midi_add_buffer(midiNote); // Data byte - Note
    midi_add_buffer(64); // Data byte - Velocity
    midi_send_buffer();
}

static void midi_note_off(u8 midiNote)
{
    midi_add_buffer(0b10000000); // Status byte
    midi_add_buffer(midiNote); // Data byte - Note
    midi_add_buffer(0); // Data byte - Velocity
    midi_send_buffer();
}

void midi_init()
{
    // Configuration de l'UART
    U2BRG = 1; // Need 31.250 bps for midi

    U2STAbits.ADDEN = 0;
    U2STAbits.URXISEL = 0; // Interrupt mode
    U2STAbits.UTXEN = 1; // Enable transmit
    U2STAbits.UTXBRK = 0; // No break next transmit
    U2STAbits.URXEN = 0; // Disable receive
    U2STAbits.UTXINV = 0; // Idle TX state is 0
    U2STAbits.UTXISEL = 0;

    U2MODEbits.STSEL = 0; // 1 seul stop bit
    U2MODEbits.PDSEL = 0;
    U2MODEbits.BRGH = 0; // Standard speed mode
    U2MODEbits.RXINV = 0; // Idle RX state is 1
    U2MODEbits.ABAUD = 0;
    U2MODEbits.LPBACK = 0;
    U2MODEbits.WAKE = 0;
    U2MODEbits.UEN = 0; //Enable pins (RX && TX)
    U2MODEbits.IREN = 0;
    U2MODEbits.SIDL = 0;
    U2MODEbits.ON = 1;

    // Interruption UART
    IFS1bits.U2TXIF = 0;
    IPC8bits.U2IP = 3;
    IEC1bits.U2TXIE = 1;

    currentNote = 0;
    bufferIndex = 0;
}

void midi_play(u8 note)
{
    midi_stop();
    currentNote = note + 24;
    midi_note_on(currentNote);
}

void midi_stop()
{
    if (currentNote)
    {
        midi_note_off(currentNote);
        currentNote = 0;
    }
}

/*
 * Interruption
 */

__ISR(_UART_2_VECTOR, IPL3AUTO) MidiBuffer()
{
    if (bufferIndex > 0)
        midi_send_buffer();
    IFS1bits.U2TXIF = 0;
}
