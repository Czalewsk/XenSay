#include <xc.h>
#include <sys/attribs.h>
#include "midi.h"
#include "events.h"

static u8 currentNote;
static u8 buffer[MIDI_BUFFER_SIZE];
static u8 bufferIndex;

static void midi_send_buffer()
{
    u8 i = 0;

    while (i < bufferIndex && !U1STAbits.UTXBF)
        U1TXREG = buffer[--bufferIndex];
    if (bufferIndex)
        IEC1bits.U1TXIE = 1;
    else
        IEC1bits.U1TXIE = 0;
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
    // Configuration des PPS
    RPA0Rbits.RPA0R = 1;
    
    // Configuration de l'UART
    U1BRG = 1; // Need 31.250 bps for midi

    U1STAbits.ADDEN = 0; // Address Character Detect bit (bit 8 of received data = 1)
    U1STAbits.URXISEL = 0; // Interrupt mode
    U1STAbits.UTXEN = 1; // Enable transmit
    U1STAbits.UTXBRK = 0; // No break next transmit
    U1STAbits.URXEN = 0; // Disable receive
    U1STAbits.UTXINV = 0; // Idle TX state is 0
    U1STAbits.UTXISEL = 0; // TX Interrupt Mode Selection bits(1)

    U1MODEbits.STSEL = 0; // 1 seul stop bit (Stop Selection bit)
    U1MODEbits.PDSEL = 0; // Parity and Data Selection bits
    U1MODEbits.BRGH = 0; // Standard speed mode
    U1MODEbits.RXINV = 0; // Idle RX state is 1
    U1MODEbits.ABAUD = 0; // Auto-Baud Enable bit
    U1MODEbits.LPBACK = 0; // UARTx Loopback Mode Select bit
    U1MODEbits.WAKE = 0; //Enable Wake-up on Start bit Detect During Sleep Mode bit
    U1MODEbits.UEN = 0; //Enable pins (RX && TX)
    U1MODEbits.IREN = 0; // IrDA® Encoder and Decoder Enable bit
    U1MODEbits.SIDL = 0; // Stop in Idle Mode bit
    U1MODEbits.ON = 1; // UARTx Mode Register

    // Interruption UART
    IFS1bits.U1TXIF = 0; //Transmit Interrupt Flag Status bit
    IPC8bits.U1IP = 3; //Interrupt Priority Control bits
    IEC1bits.U1TXIE = 0; //Transmit Interrupt Enable Control bit

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

void midi_flag_update()
{
    event_clearFlag(FLAG_MIDI);
    midi_send_buffer();
}

/*
 * Interruption
 */

// Interruption quand le buffer libere une place
__ISR(_UART_1_VECTOR, IPL3AUTO) MidiBuffer()
{
    IEC1bits.U1TXIE = 0;
    if (bufferIndex > 0)
        event_setFlag(FLAG_MIDI);
}
