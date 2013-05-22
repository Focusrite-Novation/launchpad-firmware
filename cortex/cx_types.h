#ifndef __CX_TYPES_H
#define __CX_TYPES_H
// ____________________________________________________________________________
//

#define poke(address, value)		{ *(vu32 *)( address ) = value ; }
#define pokep(address, pointer)     { *(vu32 *)( address ) = (u32) pointer ; }
#define poke_set(address, value)	{ *(vu32 *)( address ) |= value ; }
#define poke_clr(address, value)	{ *(vu32 *)( address ) &= ~ value ; }
#define peek(address)				( *(vu32 *)( address ) )
#define peek8(address)				( *(vu8  *)( address ) )

// ____________________________________________________________________________
//

typedef signed long  s32;
typedef signed short s16;
typedef signed char  s8;

typedef volatile signed long  vs32;
typedef volatile signed short vs16;
typedef volatile signed char  vs8;

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char  vu8;

// ____________________________________________________________________________
//

typedef signed long  const sc32;  /* Read Only */
typedef signed short const sc16;  /* Read Only */
typedef signed char  const sc8;   /* Read Only */

typedef volatile signed long  const vsc32;  /* Read Only */
typedef volatile signed short const vsc16;  /* Read Only */
typedef volatile signed char  const vsc8;   /* Read Only */

typedef unsigned long  const uc32;  /* Read Only */
typedef unsigned short const uc16;  /* Read Only */
typedef unsigned char  const uc8;   /* Read Only */

typedef volatile unsigned long  const vuc32;  /* Read Only */
typedef volatile unsigned short const vuc16;  /* Read Only */
typedef volatile unsigned char  const vuc8;   /* Read Only */

// ____________________________________________________________________________
//

typedef enum {FALSE = 0, TRUE = !FALSE} bool;

typedef void (*tVoidFunc)();
typedef s8 (*tCompareIndex8)(u8 HighItem, u8 LowItem);
typedef s8 (*tCompareIndex16)(u16 HighItem, u16 LowItem);

// ____________________________________________________________________________
//

#ifndef NULL
#define NULL       (void*)0
#endif

#define U8_MAX     ((u8)255)
#define S8_MAX     ((s8)127)
#define S8_MIN     ((s8)-128)
#define U16_MAX    ((u16)65535u)
#define S16_MAX    ((s16)32767)
#define S16_MIN    ((s16)-32768)
#define U32_MAX    ((u32)4294967295uL)
#define S32_MAX    ((s32)2147483647)
#define S32_MIN    ((s32)-2147483648)

#endif
