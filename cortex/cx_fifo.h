#ifndef __CX_FIFO_H
#define __CX_FIFO_H

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
