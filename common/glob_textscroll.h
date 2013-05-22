#ifndef __GLOB_TEXTSCROLL_H
#define __GLOB_TEXTSCROLL_H


extern u8 Scroll_Load(const char* Text, u8 Colour);
extern void Scroll_Poll();
extern void Scroll_Reset();

extern u16 TEXT_TIMER[];

extern u8 TextActive,TextSpeed;

#endif