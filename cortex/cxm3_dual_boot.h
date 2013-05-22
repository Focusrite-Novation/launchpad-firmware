#ifndef __CX_DUAL_BOOT_H
#define __CX_DUAL_BOOT_H


#define FLASH_BASE		0x08000000
#define VERSION_OFFSET		0x0130
#define BLVERSION_KEY_BASE	(FLASH_BASE+VERSION_OFFSET)
#define FWVERSION_KEY_BASE	(FLASH_BASE+MAIN_REL+VERSION_OFFSET)

void dual_boot_init();
void dual_boot_restart_as_bootloader();
void dual_boot_restart_normally();
void dual_boot_run_main_firmware();

void SevenToEight(u8* eightbit, const u8* sevenbit);
void EightToSeven(const u8* eightbit, u8* sevenbit);

u8 dual_boot_main_present();
u8 dual_boot_forced_bootloader();


u32 dual_boot_get_version(u8 OfBootloader);
void dual_boot_get_version_string(u8 OfBootloader, u8 AsASCII, char* Version);
char dual_boot_get_purpose(u8 OfBootloader);


#endif
