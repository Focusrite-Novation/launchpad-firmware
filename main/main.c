//////////////////////////////////////////////////////////////////////////
// Copyright 2013 Focusrite Audio Engineering Ltd.
//////////////////////////////////////////////////////////////////////////
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// (1) Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in
// the documentation and/or other materials provided with the
// distribution.
//
// (3)The name of the author may not be used to
// endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//////////////////////////////////////////////////////////////////////////

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

    sonar_demo(); // defined in sonar. c - gives examples of functions within Launchpad

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
