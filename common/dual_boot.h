#ifndef __DUAL_BOOT_H
#define __DUAL_BOOT_H

//
// TO USE DUAL BOOTING
// ____________________________________________________________________________
//
// Define the base address for the main program at the beginning of linker.ld:
//   FLASH (xr)	: ORIGIN = [insert base address here], LENGTH = 256K
// Check RAMTOP: its value will change according to your chip.
//   We use it to prove that the main firmware is present, as the top of the
//   stack is always loaded into memory location zero at the start if a program.
//

#define MAIN_REL			0x3000
__asm(".thumb_set MAIN_REL,0x3000");

#define RAMTOP              0x20005000

// last page: used for configuration data
#define CONF_REL            0xFC00
#define CONF_SANITY         0x0000
#define CONF_POWER          0x0001
#define CONF_ID             0x0002

#endif
