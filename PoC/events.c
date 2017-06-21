#include "events.h"
#include "midi.h"

void run_config(void);
void run_free(void);
void run_learn(void);
void run_simon(void);

void sr_flag_update(void);

static STATES g_current;
static STATES g_new;
static u8 g_flags;

void event_init(void)
{
    g_new = CONFIG;
    g_current = NOSTATE;
}

void event_setState(STATES state)
{
    g_new = state;
}

STATES event_getState(void)
{
    return (g_current);
}

void event_setFlag(u8 flag)
{
    g_flags |= flag;
}

void event_clearFlag(u8 flag)
{
    g_flags &= ~flag;
}

void event_update()
{
    // Run Config (Initialisation des modes)
    if (g_new != g_current)
    {
        switch(g_new)
        {
            case CONFIG:
                run_config();
                g_current = CONFIG;
                break;

            case FREE:
                run_free();
                g_current = FREE;
                break;

            case LEARN:
                run_learn();
                g_current = LEARN;
                break;

//            case SIMON:
//                run_simon();
//                g_current = SIMON;
//                break;

            default:
                g_current = NOSTATE;
                g_new = CONFIG;

        }
    }

    // Update (Appelle la fonction update des modes)
//    if (g_new == g_current)
//    {
//        // Si le mode actuel utilise le midi, appelle la fonction midi_update;
//        if (g_current == LEARN || g_current == FREE || g_current == SIMON)
//            midi_update();
//            
//    }

    // Flags
    if (g_flags & FLAG_SHIFTREGISTER)
    {
        sr_flag_update();
    }
    if (g_flags & FLAG_MIDI)
    {
        midi_flag_update();
    }
}