#include "XenSay.h"

char    *read_musicName(int *index)
{
    static int max = 10;
    char simulation[13][30] =
    {
        "Tim Hotel's mom ",
        "  Dricc's Mom   ",
        "Tamer le Retour ",
        "Tonper le Chevre",
        "Taseur le brebis",
        "Xen The biiiitch",
        "Dhiu ijnnu80nji ",
        "NIKTOI",
        "NIKTOI FORT",
        "NIKER VOUS",
        "NIKE Dric  FORT",
    };

    if (*index == -1)
        *index = max;
    else if (*index > max || !(simulation[*index]))
        *index = 0;
    return (simulation[*index]);
}

void    press_learn(u32 button)
{
    static int index = 0;

    if (button & 0x80)
    {
        lcd_write_line(read_musicName(&index), 1);
        index--;
    }
    else if (button & 0x8)
    {
        lcd_write_line(read_musicName(&index), 1);
        index++;
    }
}

void    run_learn(void)
{
    lcd_write_line("\177 Select Music \176", 0);
//    lcd_write_line("\177              \176", 1);
    setOnPressCallback(&press_learn);
}