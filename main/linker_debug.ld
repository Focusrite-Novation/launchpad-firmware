/*	____________________________________________________________________________

	modified version of the linker script for STM32F10x
	designed to pack the bootloader into base memory, so that it starts up
	upon power-up
	____________________________________________________________________________
*/

MEMORY
{
	/* 64K of FLASH, 20K of RAM
	   we can use all the RAM as the device is re-initialised upon restarting */
	FLASH  (xr)	: ORIGIN = 0x08000000, LENGTH = 64K
	RAM   (xrw)	: ORIGIN = 0x20000000, LENGTH = 20K
}


/*	____________________________________________________________________________

	default stack sizes. These are used by the startup code in order to allocate
	stacks for the different modes.
	____________________________________________________________________________
*/

__Stack_Size = 1024 ;
__Stack_Init = _estack	- __Stack_Size ;

/* There will be a link error if there is not this amount of RAM free at the end. */
_Minimum_Stack_Size = 0x100 ;

/* higher address of the user mode stack */
_estack = 0x20005000 ;


/*	____________________________________________________________________________

	sections, where the different assembly points are declared
	____________________________________________________________________________
*/

SECTIONS
{

/*	___________________________________________________________________________
	interrupt service routine vectors, in base memory
*/

	.isr_vector :
	{
		. = ALIGN(4);

		KEEP(*(.isr_vector))

		. = ALIGN(4);
	} >FLASH
	
/*	___________________________________________________________________________
	executable code and read-only data
*/

	.text :
	{
		. = ALIGN(4);
		
		*(.text)
		*(.text.*)
		*(.rodata)
        *(.rodata*)
		*(.glue_7)
        *(.glue_7t)

		. = ALIGN(4);

		/* record the start address, in FLASH, of the initialized .data section */
		_etext = .;
		_sflashdata = .;
	} >FLASH

/*	___________________________________________________________________________
	writable data, stored in FLASH, but assembled as if it were in RAM.
*/

	.data	: AT ( _sflashdata )
	{
		. = ALIGN(4);
		/* record the start address, in RAM, of the initialized .data section */
		_sramdata = .;
		
		*(.data)
		*(.data.*)
		*(.RAMtext)
		*(.textram)
		*(.textram.*)

		. = ALIGN(4);

		/* record the end address of the initialized .data section */
		_eramdata = .;
	} >RAM

/*	___________________________________________________________________________
	housekeeping
*/
	/* calculate the end address of idata, as stored in FLASH */
	_eflashdata = _sflashdata + _eramdata - _sramdata ;
	_ldata = _eramdata - _sramdata;

	/* check that we have not used all the FLASH */
	_lastdataromaddress = ORIGIN(FLASH) + LENGTH(FLASH);
	toobig = ( _eflashdata > _lastdataromaddress) ? "!!!!!!!!! FLASH IS FULL !!!!!!!!!" : 0 ;

/*	___________________________________________________________________________
	uninitialised data section, which is zero-padded upon startup
*/

	.bss :
	{
		. = ALIGN(4);
		/* This is used by the startup in order to initialize the .bss section */
		_sbss = .;
	
		*(.bss)
		*(COMMON)
	
		. = ALIGN(4);
		/* This is used by the startup in order to initialize the .bss section */
		_ebss = .;
	} >RAM
	
	PROVIDE ( end = _ebss );
	PROVIDE ( _end = _ebss );
}
