#ifndef __SURFACE_H
#define __SURFACE_H

extern void surface_init();
extern void surface_1khz();
extern void surface_blank();
extern void surface_vegas_blank();

extern void ResetTextTimer();

extern void USBUnconfigured();
extern void USBConfigured(u8 standalone);
extern void DisengageVegasAndText();

extern u8 EventFlags, VegasActive;


// Defines for Event Flag Bits used for signalling timing events

#define EVENT_1KHZ        (1<<0)
#define EVENT_200HZ       (1<<1)
#define EVENT_20HZ        (1<<2)    
#define EVENT_FLASH       (1<<3)
#define EVENT_TEXT_SCROLL (1<<4)
#define EVENT_VEGAS       (1<<5)

//_________________________________________________________________
//
// GPIO Pins

#define SW_SHIFT (1<<4) // GPIOA4
#define COL0 (1<<0) // GPIOB0
#define COL1 (1<<1) // GPIOB1
#define COL2 (1<<2) // GPIOB2

//_________________________________________________________________
//
// Control Registers

#define NBANKS          3
#define VEGAS_BANK      2

#define NCOLS           3
#define NSWBYTES        4
#define NLEDBYTES       7
#define NLEDBITS        56
#define NSW             80
#define NSWBITS         96
#define NLED            (NCOLS*NLEDBITS) /* overall LED count */

#define RELEASE_TIMEOUT 40 /* milliseconds */ 

#define PREDIV          24
#define POSTDIV         1000

#define NORMAL          0
#define PRECISION       1

// if changed also must be changed in midi.c reset routine

//#define DENOM           16 // denominator for dimming removed to allow variable duty cycle

// these times are in milliseconds
// 288ms gives compatibility with LP1
#define FLASH_TIMER     288 
#define VEGAS_TIMER     144
#define TEXT_TIMER_INIT 288 /* reloaded with correct speed value, but must be initialised to a non-zero value */

extern u8 LedValue[NBANKS][NLED], LedMasterValue[NBANKS][NLED];
extern u8 UpdateBank, DisplayBank, FlipBanks, CurrentKeyLayout, ForceFullBrightness;
extern void Plot(u8 Position, u16 Colour, u8 Bank, u8 mode);
extern u32 FlashTimer;
extern void EngageText();
extern void DisengageVegasAndText();
extern void Surface7bitLED(u8* data, u16 count);


#endif