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
// ____________________________________________________________________________
//
// Launchpad S
// Sonar 
// by Ross Chisholm
// ____________________________________________________________________________
//

#include "cx_types.h"
#include "cx_fifo.h"
#include "cxm3_usb.h"
#include "surface.h"

struct sFifo Event;


// uifu_200hz monitors buttons presses. Functions can be called from here once a button is pressed on Launchpad.
// Each button press generates four bytes of data that form the MIDI message sent to the computer.

void uifu_200hz(void) 
{
    u8 refcable, status, d1, d2;

    while (fifo_unempty(&Event))
    {
        fifo_pop4(&Event, &refcable, &status, &d1, &d2);
    
        fifo_push4(&MIDIToHst[0], refcable, status, d1, d2);
    }
}


void sonar_demo(void)
{
    // Uncomment functions to see their use


    // Plot function lights LEDs within Launchpad
    // Plot (Position, Colour, Bank, Mode)
    // Position relates to button position - buttons are number 0-79 (First row of grid = 0-8, and continues to bottom of Launchpad, Top row = 72-79
    // Colour is LED colour, see programmers reference manual (0x03 = red, 0x30 = green, 0x33 = amber)
    // Mode always use NORMAL

    //Plot(0, 0x03, 0, NORMAL); // Lights top left button red
    //Plot(9, 0x30, 0, NORMAL); // Light next button down green
    //Plot(18, 0x33, 0, NORMAL); // Lights next buttons down amber

    // Sending a MIDI message
    // Pushes 4 bytes on USB fifo
    // This will send a note on message with velocity 127
    // Arguments are USB Fifo / USB Cable Number / MIDI Status Byte / Byte 1 / Byte 2

    //fifo_push4(&MIDIToHst[0], 0x09, 0x90, 0x30, 0x7F);

    char Text[] = "Launchpad";

    if (Scroll_Load(Text, 0x33))
    {
        EngageText();
    }


}

