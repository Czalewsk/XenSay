#include <xc.h>

void sdcard_init(void)
{
    // Configuration de la pin SS
    TRISBbits.TRISB2 = 0;
    LATBbits.LATB2 = 1;
    
    // Initialise SPI
    SPI2CON = 0;
    SPI2BRG = 1;
    
    SPI2CONbits.MSTEN = 1; // Le pic est le maitre
    SPI2CONbits.CKE = 1;
    SPI2CONbits.CKP = 0; // Idle clock = low
    SPI2CONbits.ON = 1;
}