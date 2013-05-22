#ifndef __CX_USB_H
#define __CX_USB_H

#include "cx_fifo.h"

extern struct sFifo MIDIToHst[], MIDIToDev[];
extern struct sFifo MIDIToHstOff[];

extern void usb_init();
extern void usb_enable();
extern void usb_disable();
extern void usb_poll();
extern void usb_200hz();

#endif