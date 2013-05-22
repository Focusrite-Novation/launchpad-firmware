// ____________________________________________________________________________
//
// Launchpad S
// Sonar 
// by Ross Chisholm
// © 2013 Focusrite Audio Engineering Ltd
// ____________________________________________________________________________
//

#include "cx_types.h"
#include "cx_fifo.h"
#include "cxm3_usb.h"

struct sFifo Event;


void uifu_200hz(void)
{
    u8 refcable, status, d1, d2;

    while (fifo_unempty(&Event))
    {
        fifo_pop4(&Event, &refcable, &status, &d1, &d2);
    
        fifo_push4(&MIDIToHst[0], refcable, status, d1, d2);
    }
}
