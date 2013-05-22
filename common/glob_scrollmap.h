#ifndef __GLOB_SCROLLMAP_H
#define __GLOB_SCROLLMAP_H


#define INV 80 /* invalid co-ordinate */

extern const u8 ScrollText[];
extern const u8 ScrollUp[];
extern const u8 ScrollDown[];
extern const u8 ScrollLeft[];
extern const u8 ScrollRight[];

extern void Darken(u8* Colour);
extern void ScrollPlot(u8 Position, u8 Colour, u8 Bank, s8 XVec, s8 YVec);


#endif