#include "events.h"

void run_config(void);
void run_free(void);
void run_learn(void);
void run_simon(void);

void sr_flag_update(void);

static STATES g_current;
static STATES g_new;
static u32 g_flags;

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

void event_setFlag(u32 flag)
{
    g_flags |= flag;
}

void event_clearFlag(u32 flag)
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
                g_current = CONFIG;
                run_config();
                break;

            case FREE:
                g_current = FREE;
                run_free();
                break;

            case LEARN:
                g_current = LEARN;
                run_learn();
                break;

            //case SIMON:
            //    g_current = SIMON;
            //    run_simon();
            //    break;

            default:
                g_current = NOSTATE;
                g_new = CONFIG;

        }
    }

    // Update (Apelle la fonction update des modes)
    if (g_new == g_current)
    {

    }

    // Flags
    if (g_flags & FLAG_SHIFTREGISTER)
    {
        sr_flag_update();
        g_flags &= ~FLAG_SHIFTREGISTER;
    }
}