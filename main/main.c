// ____________________________________________________________________________
//
// Launchpad S
// by Ross Chisholm
// © 2012 Focusrite Audio Engineering Ltd
// ____________________________________________________________________________
//

#include "cx_types.h"
#include "cx_fifo.h"
#include "cxm3_registers.h"
#include "cxm3_dual_boot.h"
#include "cxm3_usb.h"
#include "dual_boot.h"
#include "glob_init.h"
#include "glob_textscroll.h"
#include "surface.h"
#include "midi.h"
#include "vegas.h"
#include "deviceid.h"
#include "sonar.h"

extern u8 configuration_descriptor[];


// ____________________________________________________________________________
//

int main()
{
    if (!peek8(FLASH_BASE + CONF_REL + CONF_POWER))
    {
        ForceFullBrightness = TRUE;
        configuration_descriptor[8] = 250;
    }

    dual_boot_init();
    DeviceID_SetupPID();
    glob_init_clocks();
    glob_init_gpios();
    surface_blank();
    midi_parsers_init();
    surface_init();
    usb_init();
    usb_enable();

    while (1)
    {
        usb_poll();
        midi_parsers_poll();

        if (EventFlags & EVENT_1KHZ)
        {
            // 1kHz
            EventFlags = (EventFlags & ~EVENT_1KHZ);
            surface_1khz();
        }

        if (EventFlags & EVENT_200HZ)
        {
            // 200Hz
            EventFlags = (EventFlags & ~EVENT_200HZ);
        
            usb_200hz();
            uifu_200hz();
        }

        if (EventFlags & EVENT_20HZ)
        {
            // 20Hz
            EventFlags = (EventFlags & ~EVENT_20HZ);
        }

        if (EventFlags & EVENT_FLASH) // set from Timer 4
        {
            // Flash timer
            EventFlags = (EventFlags & ~EVENT_FLASH);

            if ((FlipBanks)  && (!TextActive))
            {
                DisplayBank = (DisplayBank == 0) ? 1 : 0;
            }
        }

        if (EventFlags & EVENT_TEXT_SCROLL)
        {
            // Scroll timer
            EventFlags = (EventFlags & ~EVENT_TEXT_SCROLL);

            if (TextActive)
            {
                Scroll_Poll();
            }
        }

        if (EventFlags & EVENT_VEGAS)
        {
            // Vegas timer
            EventFlags = (EventFlags & ~EVENT_VEGAS);

            if (VegasActive)
            {
                Vegas_Poll();
            }
        }
    }
}
