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
// MIDI routines
// by Ross Chisholm
// ____________________________________________________________________________
//

#include "cx_types.h"
#include "cx_fifo.h"
#include "cx_midi_parser.h"
#include "cxm3_registers.h"
#include "cxm3_usb.h"
#include "cxm3_dual_boot.h"
#include "dual_boot.h"
#include "glob_textscroll.h"
#include "glob_surfacemap.h"
#include "surface.h"
#include "midi.h"



struct sMIDIParserRx USBParserToDev;
struct sMIDIParserTx USBParserToHst;

u8 UserByte;
u8 RunningStatusCounter, RunningUpdate, DutyCycleMultiplier = 16;

u8 ChallengeResponse [] = {0xF0, 0x00, 0x20, 0x29, 0x06, 0x00, 0x00, 0xF7};
const u8 DEVICEINQUIRY []     = {0xF0, 0x7E, 0x00, 0x06, 0x01, 0xF7};
u8 DEVICERESPONSE[]     = {0xF0, 0x7E, 0x00, // 0-2 : device inquiry, device ID
						   0x06, 0x02,       // 3-4 : general information, identity reply
						   0x00, 0x20, 0x29, // 5-7 : manufacturer ID
						   0x20, 0x00,       // 8-9 : device family code LSB first
						   0x00, 0x00,		 // 10-11 : device family member code (we send the launchpad's ID)
						   0x00, 0x00, 0x00, 0x00, // 12-15 : device specific software revision. we send the build number in BCD.
						   0xF7};            // 16 : end.

u8 Challenge[4];
u8 DataIn[540], DataOut[540];

void midi_parsers_init() // set up for midi parsers to work
{
    USBParserToHst.IsClassCompliant = TRUE;
    USBParserToDev.OnMIDIData = MIDIData;
    USBParserToDev.OnMIDISysEx = MIDISysex;
    USBParserToDev.Reference = 1;
    USBParserToDev.SysExBuffer = DataIn;
    USBParserToDev.SysExMaxSize = sizeof(DataIn);
}

void midi_parsers_poll() // send/receive any messages
{
    midi_parse_rx_usb(&MIDIToDev[0], &USBParserToDev);
    midi_parse_tx_sysex_fill(&MIDIToHst[0], &USBParserToHst);
}

// ____________________________________________________________________________
//

u16 CalculateDutyRatio(u8 type, u8 d2)
{
    u8 numerator, denominator;

    if (!type) // its a 0x1E message
    {
        denominator = (d2 & 0xF) + 3;
        numerator = ((d2>>4) & 0xF) + 1;
    }
    else // its a 0x1F message
    {
        denominator = (d2 & 0xF) + 3;
        numerator = ((d2>>4) & 0xF) + 9;
    }

    DutyCycleMultiplier = ((numerator*0x50)/denominator);

}

// ____________________________________________________________________________
//

void CalculateSurface()
{
    u8 i,j;

    for (i=0; i<NBANKS; i++)
    {
        for (j=0; j<NLED; j++)
        {
            u16 newbrightness;

            newbrightness = (LedMasterValue[i][j] * DutyCycleMultiplier)/16;
            if (newbrightness > 0x3F) newbrightness = 0x3F;

            LedValue[i][j] = newbrightness;
        }
    }
}

// ____________________________________________________________________________
//

u8 CheckNovationMessage(u8* data)
{
    return ((data[1] == 0x00) && (data[2] == 0x20) && (data[3] == 0x29));
}

// ____________________________________________________________________________
//

void ScrollMessage(u8* data, u16 count)
{
    u8 response;
                         // data   // colour
    response = Scroll_Load(&data[6], data[5]);
    if (response) EngageText(); // only engage text if we have a valid message to display.
    else DisengageVegasAndText();
}

// ____________________________________________________________________________
//

void VersionMessage(u8* data, u16 count)
{
    u8 i;
	u32 v;
    // top and tail
    USBParserToHst.SysExBuffer = DataOut;
    USBParserToHst.SysExCount = 19;
    midi_parse_tx_sysex_init(&USBParserToHst);
    DataOut[5] = 0x70;

    // bootloader version
	v = peek(BLVERSION_KEY_BASE);
	for (i=10; i>=6; i--)
	{
		DataOut[i] = v & 0x0f;
		v >>= 4;
	}

    // main firmware version
	v = peek(FWVERSION_KEY_BASE);
    for (i=15; i>=11; i--)
	{
		DataOut[i] = v & 0x0f;
		v >>= 4;
	}

	DataOut[16] = MAIN_REL>>10; // size of bootloader in kilobytes
    DataOut[17] = 1;            // protocol version number
}

// ____________________________________________________________________________
//

u8 CalculateXY(u8 d1)
{
    u8 row, col, actual_position;

    // X/Y layout
    col = d1 & 0x0F; // find column number
    row = (d1>>4) & 0x0F; // find row number
    if (col > 8) col = 8; // catch invalid no's 9-15

    actual_position = (row * 9) + col;

    return actual_position;
}

// ____________________________________________________________________________
//

#define COPYBIT (1<<2)
#define CLEARBIT (1<<3)

void midi_noteon(u8 d1, u8 d2)
{
    u8 col, row, actual_position, drum_button, led_brightness, other_bank;

    if (RunningUpdate)
    {
        // running update message
        actual_position = d1;
    }
    else if (!CurrentKeyLayout)
    {
        actual_position = CalculateXY(d1);
    }
    else if (CurrentKeyLayout)
    {
        // Drum Rack layout
        if ((d1 >= 0x24) && (d1 <= 0x6B))
        {
            drum_button = d1 - 0x24;
            actual_position = DRUM_RACK_TO_XY[drum_button];
        }
        else if ((d1 >= 0x6C) && (d1 <= 0x73))
        {
            actual_position = d1 - 0x24;
        }
        else return; // don't respond to invalid button
    }
    else return;

	Plot(actual_position, d2, UpdateBank, NORMAL);
    other_bank = (UpdateBank == 0) ? 1 : 0;

    if (d2 & COPYBIT)
    {
        Plot(actual_position, d2, other_bank, NORMAL);
    }
    else if (d2 & CLEARBIT)
    {
        Plot(actual_position, 0, other_bank, NORMAL);
    }
}

// ____________________________________________________________________________
//

void midi_runningupdate(u8 d1, u8 d2)
{
    u8 actualbutton;

    if (RunningStatusCounter <= 79)
    {
        RunningUpdate = TRUE; // turn on notification for midi_noteon
        actualbutton = RUNNING_STATUS_ORDER[RunningStatusCounter]; // calculate next button to address
        midi_noteon(actualbutton, d1); // set the led
        RunningStatusCounter++;

        actualbutton = RUNNING_STATUS_ORDER[RunningStatusCounter]; // calculate next button to address
        midi_noteon(actualbutton, d2); // set the led
        RunningStatusCounter++;
    }
}

// ____________________________________________________________________________
//

void CopyBanks() // copying one led bank to another
{
    u8 i;
    u8 other_bank = (DisplayBank == 0) ? 1 : 0;

    for (i=0; i<NLED; i++)
    {
        LedMasterValue[other_bank][i] = LedMasterValue[DisplayBank][i];
        LedValue[other_bank][i] = LedValue[DisplayBank][i];   
    }
}

// ____________________________________________________________________________
//

void AllOn(u8 Intensity)
{
    u8 i;
    for (i=0; i<80; i++)
    {
        Plot(i,Intensity,0, NORMAL); // set bank zero
        Plot(i, 0, 1, NORMAL);
    }
    // Generally reset
    CurrentKeyLayout = 0;
    FlipBanks = 0;
    UpdateBank = 0;
    DisplayBank = 0;
}

// ____________________________________________________________________________
//

void ResetMessage(u8* data, u16 count)
{
    // check device ID: if it's not Launchpad firmware,
    // we're not going to unlock the FLASH.
    if ((data[6] != 0x00) || (data[7] != 0x20)) return;
    dual_boot_restart_as_bootloader();
}

// ____________________________________________________________________________
//

u8 DeviceInquiry(u8* data)
{
    u8 i = 0, match = TRUE;
    while ((i < sizeof(DEVICEINQUIRY)) && match)
    {
        if ((i == 2) && (data[i] == 0x7F)) // 'to all devices'
        {
            i++;
        }
        else if (data[i] == DEVICEINQUIRY[i])
        {
            i++;
        }
        else
        {
            match = FALSE;
        }
    }
    return match;            
}

// ____________________________________________________________________________
//


void MIDISysex(u8 refcable, u8* data, u16 count)
{
    if (CheckNovationMessage(data))
    {
        if (data[4] == 0x09) ScrollMessage(data,count);
        //else if (data[4] == 0x0A) Surface7bitLED(data, count);
        else if (data[4] == 0x00)
        {
            if      (data[5] == 0x70) VersionMessage(data,count);
            else if (data[5] == 0x71) ResetMessage(data,count);
        }
    }
    else if (DeviceInquiry(data))
    {
        // System common device inquiry
		u32 v;
		u8 i;
		DEVICERESPONSE[10] = peek8((FLASH_BASE + CONF_REL + CONF_ID)); // launchpad ID
        v = peek(FWVERSION_KEY_BASE);
		for (i=15; i>=12; i--)
		{
			DEVICERESPONSE[i] = v & 0x0f; // up to v9999
			v >>= 4;
		}
		
		USBParserToHst.SysExBuffer = (u8 *)DEVICERESPONSE;
        USBParserToHst.SysExCount = sizeof(DEVICERESPONSE);
    }
}

// ____________________________________________________________________________
//

void QuitRunningStatus()
{
    RunningStatusCounter = 0; // reset running status counter if this is called
    RunningUpdate = FALSE; // turn off running update because we've received a status message
}
// ____________________________________________________________________________
//

void MidiCCZero(u8 d1, u8 d2)
{
    if (d2 == 0x00)
    {
        // reset launchpad
        surface_blank();
        CurrentKeyLayout = 0;
        FlipBanks = 0;
        UpdateBank = 0;
        DisplayBank = 0;
        DutyCycleMultiplier = 16;
        
        if (!peek8(FLASH_BASE + CONF_REL + CONF_POWER))
        {
            ForceFullBrightness = TRUE;
        }
        else ForceFullBrightness = FALSE;
    
    }
    else if (d2 == 0x01)
    {
        // X-Y mapping mode
        CurrentKeyLayout = 0;
    }
    else if (d2 == 0x02)
    {
        // drum rack mapping mode
        CurrentKeyLayout = 1;
    }
    else if (d2 == 0x03)
    {
        ForceFullBrightness = TRUE;
    }
    else if (d2 == 0x04)
    {
        ForceFullBrightness = FALSE;
    }
    else if (d2 == 0x10)
    {
        // return user byte
        fifo_push4(&MIDIToHst[0], 0x0B, 0xB0, 0x10, UserByte);
    }
    else if ((d2 >= 0x20) && (d2 <= 0x3D) && (!TextActive))
    {
        FlashTimer = FLASH_TIMER; // reset flash timer

        DisplayBank  = (d2 & 1) ? 1 : 0; // sets display bank
        UpdateBank   = (d2 & 4) ? 1 : 0; // sets update bank
        FlipBanks    = (d2 & 8) ? 1 : 0; // sets flashing
        if (d2 & 16) CopyBanks(); // copy one bank to the other
    }
    else if (d2 == 0x7D) // current consumption test dim brightness
    {
        AllOn(0x11);
    }
    else if (d2 == 0x7E) // current consumption test half brightness
    {
        AllOn(0x22);
    }
    else if (d2 == 0x7F) // current consumption test full brightness
    {
        AllOn(0x33);
    }
}

// ____________________________________________________________________________
//

void MIDIData(u8 refcable, u8 status, u8 d1, u8 d2)
{

    if (status == 0xB0)
    {
        QuitRunningStatus();

        if (d1 == 0x10)
        {
            // set user byte with new data
            UserByte = d2;
            // send user byte status return
            fifo_push4 (&MIDIToHst[0], 0x0B, 0xB0, 0x10, UserByte);
        }
        else if (d1 == 0x1E)
        {
            CalculateDutyRatio(0, d2);
            CalculateSurface();
        }
        else if (d1 == 0x1F)
        {
            CalculateDutyRatio(1, d2);
            CalculateSurface();
        }
        else if ((d1 >= 0x68) && (d1 <= 0x6F))
        {
            // catch cc messages for setting leds on top row and convert them so they work with arrays and note ons

            if (!CurrentKeyLayout)
            {
                midi_noteon (d1 - 0x68 + 0x80, d2);
            }
            else midi_noteon (d1 + 0x4, d2); // cc messages when in drum rack mode need to be treated differently
        }
        else if (d1 == 0x00)
        {
            // call separate routine for dealing with d1 = 0x00
            MidiCCZero(d1, d2);
        }
    }
    else if (status == 0x90)
    {
        // note on message, pass to note on routine
        QuitRunningStatus();
        if ((d1 >= 0x00) && (d1 <= 0x88))
        {
            midi_noteon(d1, d2);
        }
    }
    else if (status == 0x80)
    {
        // convert all note off messages into a form that can be passed to note on routine
        QuitRunningStatus();
        u8 noteoff;
        noteoff = d2 & 0xC; // make all led data 0
        if ((d1>=0x00) && (d1<=0x78))
        {
            midi_noteon(d1, noteoff);
        }
    }
    else if (status == 0x92) // running update message
    {
        midi_runningupdate(d1,d2);
    }
}
