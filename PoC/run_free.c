#include "XenSay.h"
#include "button.h"

static void onPressButton(u32 button)
{

}

static void onReleaseButton(u32 button)
{
    
}

void run_free(void)
{
    setOnPressCallback(&onPressButton);
    setOnReleaseCallback(&onReleaseButton);
}