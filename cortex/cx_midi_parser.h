#ifndef __CX_MIDI_PARSER_H
#define __CX_MIDI_PARSER_H

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


typedef void (*tOnMIDIData) (u8 refcable, u8 status, u8 d1, u8 d2);
typedef void (*tOnSysExData)(u8 refcable, u8* data, u16 count);

#define INSYSEX (1<<7)
#define MP_STATUS 0

// ____________________________________________________________________________
//

struct sMIDIParserRx
{
    // from the outside world to us
    u8* SysExBuffer;    // this stays where it is
    u16 SysExCount;     // this increases as data is written
    u16 SysExMaxSize;
    u8 Reference;
    // used for byte-streaming inputs, and occasionally in USB parsing from Mac.
    u8 Packet[3];
    u8 ExpectedSize;
    u8 SysExOrData;     // =1: next byte is first data byte
                        // =2: next byte is second data byte
                        // =INSYSEX: within a SysEx
    // callbacks
    tOnMIDIData OnMIDIData;
    tOnSysExData OnMIDISysEx;
};

// ____________________________________________________________________________
//

struct sMIDIParserTx
{
    // from us to the outside world
    u8* SysExBuffer;        // this travels as data is written
    s16 SysExCount;         // this descends as data is transmitted
                            // transmission finished when SysExCount == 0
                            // (for long buffers, this may not happen at the first attempt)
    u8  IsClassCompliant;   // set to TRUE for class compliant format; FALSE for DIN or vendor-specific format.
};

// ____________________________________________________________________________
// Packetising
//

extern void midi_parse_tx_sysex_init(struct sMIDIParserTx* Context);
extern   u8 midi_parse_rx_sysex_test(u8 *Buffer);

// ____________________________________________________________________________
// Sending MIDI
//

extern void midi_parse_tx_message(struct sFifo *OutputFifo, struct sMIDIParserTx* Context, u8 Status, u8 Data1, u8 Data2);
extern void midi_parse_tx_sysex_fill(struct sFifo *OutputFifo, struct sMIDIParserTx* Context);

// ____________________________________________________________________________
// Receiving MIDI
//

extern void midi_parse_rx_byte(u8 Byte, struct sMIDIParserRx* Context);
extern void midi_parse_rx_byte_stream(struct sFifo *InputFifo, struct sMIDIParserRx* Context);
extern void midi_parse_rx_byte_buffer(u8 *Buffer, u32 Count, struct sMIDIParserRx* Context);
extern void midi_parse_rx_usb(struct sFifo *InputFifo, struct sMIDIParserRx* Context);
    
#endif