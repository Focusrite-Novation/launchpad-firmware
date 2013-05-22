#ifndef __CX_FIFO_H
#define __CX_FIFO_H

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

// we use the natural overflow of an unsigned char to do our pointer wrapping for us.
// the FIFO length in use is 128 bytes owing to a rather lovely optimisation
// (I am indebted to Mr. Page)
#define FIFO_SIZE 256

struct sFifo	{	u8 Fifo[FIFO_SIZE];
					u8 NextRead;
					u8 NextWrite;
				};

// ____________________________________________________________________________
// Prototypes
//

extern void fifo_push1(struct sFifo* fifo, u8 value);
extern u8 fifo_pop1(struct sFifo* fifo);
extern void fifo_push2(struct sFifo* fifo, u8 v1, u8 v2);
extern void fifo_pop2(struct sFifo* fifo, u8* v1, u8* v2);
extern void fifo_push4(struct sFifo* fifo, u8 v1, u8 v2, u8 v3, u8 v4);
extern void fifo_pop4(struct sFifo* fifo, u8* v1, u8* v2,u8* v3,u8* v4);
extern void fifo_flush(struct sFifo* fifo);
extern u8 fifo_unfull(struct sFifo* fifo);
extern u8 fifo_unempty(struct sFifo* fifo);
    
#endif
