#include "XenSay.h"

void    spi_init(void)
{
    int cData = 0;
    
    // PPS
    TRISAbits.TRISA1 = 1; // Set SDI1 to input
    SDI1Rbits.SDI1R = 0;
    RPB11Rbits.RPB11R = 3; // Set SDO1 PPS

    TRISBbits.TRISB14 = 0; // SCK1
    LATBbits.LATB14 = 0;

    //Etape 1
    IEC1bits.SPI1EIE = 0;
    IEC1bits.SPI1RXIE = 0;
    IEC1bits.SPI1TXIE = 0;

    //Etape 2
    SPI1CON = 0;

    //Etape 3
    cData = SPI1BUF;
    SPI1BUF = 0;

    //Etape 4
    // N'existe pas sur notre pic RIP :'(

    //Etape 5
    // IFSO = Interrumpt Flag Status
    // IPCS = Interrumpt Priority Control
    // IECx: Interrupt Enable Control Register
    IFS1bits.SPI1TXIF = 0; // SPI1 Transmitter Interrupt Request Flag Bit
    IFS1bits.SPI1RXIF = 0; // SPI1 Receive Interrupt Request Flag Bit
    IFS1bits.SPI1EIF = 0; // SPI1 Error Interrupt Request Flag Bit
    IPC7bits.SPI1IP = 6; // SPI1 Interrupt Priority (0 a 7)
    IPC7bits.SPI1IS = 1; // SPI1 Interrupt Sub-Priority (0 a 3)
    IEC1bits.SPI1EIE = 1; //Gestion d'erreurs
    IEC1bits.SPI1RXIE = 1; // Gestion de recois
    IEC1bits.SPI1TXIE = 1; //Gestion de transmission des donnees

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
    SPI1CONbits.MODE32 = 1; // Set 32bits SPI
    SPI1CONbits.ENHBUF = 0;
    
    //Etape 9
    SPI1CONbits.ON = 1;
}
