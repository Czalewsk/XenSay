#include "XenSay.h"

char    *read_musicName(int *index)
{
    char simulation[13][30] =
    {
        "Tim Hotel's mom ",
        "  Dricc's Mom   ",
        "Tamer le Retour ",
        "Tonper le Chevre",
        "Taseur le brebis",
        "   Xen The GOD  ",
        "    Dhiu ijnnu80nji TX   uyuktyfu5656465465465     ",
        "NIKTOI",
        "NIKTOI FORT",
        "NIKER VOUS",
        "NIKER VOUS FORT",
        NULL
    };

 //   if (i < )
    return (NULL);
}

void    press_learn(u32 button)
{

}

void    run_learn(void)
{
    lcd_write_line("  Select Music  ", 0);
    lcd_write_line("\177              \176", 1);
    setOnPressCallback(&press_learn);
}