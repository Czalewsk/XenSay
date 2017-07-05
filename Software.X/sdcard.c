#include <xc.h>
#include "sdcard.h"
#include "XenSay.h"

static u8 flags;

static u8 SPI(const u8 send)
{
    SPI2BUF = send;
    while (!SPI2STATbits.SPITBE);
    while (!SPI2STATbits.SPIRBF);
    return (SPI2BUF);
}

static u8 sd_wait_rep()
{
    u16 i = 0;
    u8 data = 0xff;

    do
    {
        data = SPI(0xff);
        ++i;
    } while (i <= 256 && data == 0xff);
    return (data);
}

static u8 sd_send_cmd(const u8 cmd, const u8 arg1, const u8 arg2,
        const u8 arg3, const u8 arg4, const u8 crc)
{
    SPI((cmd | 0x40) & 0x7f); // Send CMD
    SPI(arg1);
    SPI(arg2);
    SPI(arg3);
    SPI(arg4);
    SPI(crc | 0x1);
    
    return (sd_wait_rep());
}

static u8 sd_error(char *str)
{
    LATBbits.LATB13 = 1;
    lcd_write_line(str, 0);
    return (0);
}

void sdcard_init(void)
{   
    // Configuration des PPS
    TRISBbits.TRISB2 = 1;
    SDI2Rbits.SDI2R = 4;
    RPB5Rbits.RPB5R = 4;
    
    // Configuration de la pin SS
    TRISBbits.TRISB13 = 0;
    LATBbits.LATB13 = 1;
    
    // Initialise SPI
    SPI2CON = 0;
    SPI2BRG = 1;
    
    SPI2CONbits.MSTEN = 1; // Le pic est le maitre
    SPI2CONbits.CKE = 0;
    SPI2CONbits.CKP = 0; // Idle clock = low
    SPI2CONbits.ON = 1;
    
    // Interruption config
    IFS1bits.SPI2EIF = 0;
    IFS1bits.SPI2RXIF = 0;
    IFS1bits.SPI2TXIF = 0;
    IPC9bits.SPI2IP = 6;
    IPC9bits.SPI2IS = 0;
    IEC1bits.SPI2EIE = 0;
    IEC1bits.SPI2RXIE = 0;
    IEC1bits.SPI2TXIE = 0;
}

u8 sdcard_start(void)
{
    u8 rep;
    u16 i;
    
    // Initialisation de la carte sd
    flags = 0;
    
    // Passage en mode natif de la carte (512 coups de clock si l'état précedent = unfinished read)
    LATBbits.LATB13 = 1;
    for (i = 0; i < 10; ++i)
        SPI(0xff);
    
    // Reset the sdcard with CMD0
    LATBbits.LATB13 = 0;
    if (sd_send_cmd(0, 0, 0, 0, 0, 0x95) == 255)
        return (sd_error("    NO SDCARD   "));
    
    // Check the sdcard version and voltage with CMD8
    if ((rep = sd_send_cmd(8, 0, 0, 1, 0xaa, 0x87)) == 255) // No support current voltage
        return (sd_error("NO SUPPORT 3.3V "));
    if (rep & 0x4)
        return (sd_error(" BAD SD VERSION "));
    if (rep != 0x1)
        return (sd_error("   SD ERROR 1   "));
    SPI(0xff); // Command version + reserved
    SPI(0xff); // Reserved
    SPI(0xff); // Reserved + voltage
    SPI(0xff); // Echo back
    
    // Finish initialization with ACMD41
    i = 0;
    do {
        // CMD55
        if (sd_send_cmd(55, 0, 0, 0, 0, 0) & 0x7e)
            return (sd_error("   SD ERROR 2   "));

        // ACMD41
        if ((rep = sd_send_cmd(41, 0x40, 0, 0, 0, 0)) & 0x7e)
            return (sd_error("   SD ERROR 3   "));
    } while (rep & 0x1 && i++ < 256);
    
    if (rep != 0)
        return (sd_error("   FAIL INIT    "));
    
    // Check capacity card support with CMD58
    if (sd_send_cmd(58, 0, 0, 0, 0, 0) != 0)
        return (sd_error("   SD ERROR 4   "));
    if (SPI(0xff) & 0x40)// Get CCS
        flags |= FLAGS_CCS;
    SPI(0xff);
    SPI(0xff);
    SPI(0xff);

    // Set block len to 512 bytes if sdsc
    if (flags & FLAGS_CCS)
    {
        if (sd_send_cmd(16, 0, 0, 0x2, 0, 0) != 0)
            return (sd_error(" SD ERROR SDSC  "));
    }
    
    LATBbits.LATB13 = 1;
    
    return (1);
}

u8 *sdcard_read(u32 addr)
{
    static u8 block[512];
    u16 i;
    
    if (!(flags & FLAGS_CCS))
        addr *= 512;
    
    LATBbits.LATB13 = 0;
    
    // Request read block
    if (sd_send_cmd(17, addr >> 24, addr >> 16, addr >> 8, addr, 0) != 0)
    {
        sd_error(" SD READ ERROR  ");
        return (0);
    }
    
    // Wait data
    if (sd_wait_rep() != 0xfe)
    {
        sd_error("SD READ TOKEN ER");
        return (0);
    }
    
    // Read data block (512 bytes)
    i = 0;
    while (i < 512)
        block[i++] = SPI(0xff);
    
    // Ignore CRC
    SPI(0xff);
    SPI(0xff);
    
    LATBbits.LATB13 = 0;
    
    return (block);
}