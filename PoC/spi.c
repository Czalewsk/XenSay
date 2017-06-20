#include "XenSay.h"

void    spi_init(void)
{
    int cData = 0;

    TRISFbits.TRISF6 = 0;
    LATFbits.LATF6 = 0;

    //Etape 1
    IEC0bits.SPI1EIE = 0;
    IEC0bits.SPI1RXIE = 0;
    IEC0bits.SPI1TXIE = 0;

    //Etape 2
    SPI1CON = 0;

    //Etape 3
    cData = SPI1BUF;

    //Etape 4
    // N'existe pas sur notre pic RIP :'(

    //Etape 5
    // IFSO = Interrumpt Flag Status
    // IPCS = Interrumpt Priority Control
    // IECx: Interrupt Enable Control Register
    IFS0bits.SPI1TXIF = 0; // SPI1 Transmitter Interrupt Request Flag Bit
    IFS0bits.SPI1RXIF = 0; // SPI1 Receive Interrupt Request Flag Bit
    IFS0bits.SPI1EIF = 0; // SPI1 Error Interrupt Request Flag Bit
    IPC5bits.SPI1IP = 5; // SPI1 Interrupt Priority (0 a 7)
    IPC5bits.SPI1IS = 1; // SPI1 Interrupt Sub-Priority (0 a 3)
    IEC0bits.SPI1EIE = 1; //Gestion d'erreurs
    IEC0bits.SPI1RXIE = 1; // Gestion de recois
    IEC0bits.SPI1TXIE = 1; //Gestion de transmission des donnees

    //Etape 6
    //BRG = Baud Rate Generator
    SPI1BRG = 32; //  0 est le + rapide, 127 est le + lent

    //Etape 7
    SPI1STATbits.SPIROV = 0;  // Receive Overflow Flag Bit

    //Etape 8
    SPI1CONbits.CKP = 1; //CKP: Clock Polarity Select bit (1 -> HIGHT lvl, 0 -> LOW lvl)
    SPI1CONbits.CKE = 1; // CKE: SPI Clock Edge Select bit ; 1 = Serial output data changes on transition from active clock state to idle clock state (see CKP bit)
    SPI1CONbits.MSTEN = 1; //MSTEN: Master Mode Enable bit; 1 = Master mode
    SPI1CONbits.SMP = 1; //SMP: SPI Data Input Sample Phase bit; 1 = Input data sampled at end of data output time (if MSTEN = 1)

    //Etape 9
    SPI1CONbits.ON = 1;
}
