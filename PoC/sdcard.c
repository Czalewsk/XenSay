#include <xc.h>

void sdcard_init(void)
{
    SPI2CON = 0;
    SPI2BRG = 1;
}