#include "XenSay.h"
#include "events.h"
#include "button.h"

static  s8   imusic;
static  char music_name[50];

void    read_musicName(void)
{
    u8  i = 0;
    static int max = 11;
    char simulation[13][50] =
    {
        "TEST shift du lcd avec un text a la con",
        "  Xen il a pas soudeeeeeee ",
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

    if (imusic <= -1)
        imusic = max - 1;
    else if (imusic >= max)
        imusic = 0;
    while (simulation[imusic][i])
    {
        music_name[i] = simulation[imusic][i];
        i++;
    }
    music_name[i] = '\0';
}

void    press_learn(u32 button)
{
    if (button & 0x80)
        imusic--;
    else if (button & 0x8)
        imusic++;
    else if (button & 0x40)
    {
        event_setState(CONFIG);
        timer5Off();
        return ;
    }
    read_musicName();
    lcd_shift(music_name, 1);
}

void    run_learn(void)
{
    imusic = 0;
    read_musicName();
    lcd_write_line("\177 Select Music \176", 0);
    lcd_shift(music_name, 1);
    setOnPressCallback(&press_learn);
}