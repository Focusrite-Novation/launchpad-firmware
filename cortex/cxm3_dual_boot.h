#ifndef __CX_DUAL_BOOT_H
#define __CX_DUAL_BOOT_H

//////////////////////////////////////////////////////////////////////////
// Copyright 2013 Focusrite Audio Engineering Ltd.
//////////////////////////////////////////////////////////////////////////
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// (1) Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in
// the documentation and/or other materials provided with the
// distribution.
//
// (3)The name of the author may not be used to
// endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//////////////////////////////////////////////////////////////////////////


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
