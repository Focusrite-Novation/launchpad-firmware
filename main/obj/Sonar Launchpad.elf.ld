
/*
!!! Primary linker script file generated automatically !!!
This file contains the input and output files names
It also includes the secondary/main linker script that is specified in the Ride options (default or custom)
*/

SEARCH_DIR(".")
SEARCH_DIR("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj")
SEARCH_DIR("C:\Raisonance\Ride\Lib\ARM")
STARTUP("startup.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\glob_textscroll.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\glob_font.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\glob_init.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\glob_scrollmap.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\glob_surfacemap.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\main.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\midi.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\sonar.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\cortex\cx_fifo.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\cortex\cx_midi_parser.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\cortex\cx_switch.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\cortex\cxm3_dual_boot.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\cortex\cxm3_flash.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\cortex\cxm3_usb.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\startup.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\deviceid.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\vegas.o")
INPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\surface.o")
EXTERN( __io_putchar )
EXTERN( _write )
GROUP(
"STM32x_io_putchar_thumb.a"
"std_sbrk_thumb.lib"
"smallprintf_thumb.a"
"libc.a"
"libm.a"

)
INCLUDE "main\linker_debug.ld"
OUTPUT("C:\Users\rosschisholm\Documents\Work\Sonar Launchpad\main\obj\Sonar Launchpad.elf")
