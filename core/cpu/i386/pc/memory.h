#ifndef GRUB_MEMORY_MACHINE_H
#define GRUB_MEMORY_MACHINE_H

#include "core/grub-symbol.h"
#ifndef ASM_FILE
#include "core/grub-types.h"
#include "core/grub-err.h"
#include "core/grub-memory.h"
#endif

#include "core/cpu/i386/memory.h"
#include "core/cpu/i386/memory_raw.h"

#include "core/grub-offsets.h"

/* The area where GRUB is decompressed at early startup.  */
#define GRUB_MEMORY_MACHINE_DECOMPRESSION_ADDR	0x100000

/* The address of a partition table passed to another boot loader.  */
#define GRUB_MEMORY_MACHINE_PART_TABLE_ADDR	0x7be

/* The address where another boot loader is loaded.  */
#define GRUB_MEMORY_MACHINE_BOOT_LOADER_ADDR	0x7c00

#define GRUB_MEMORY_MACHINE_BIOS_DATA_AREA_ADDR	0x400

#ifndef ASM_FILE

/* See http://heim.ifi.uio.no/~stanisls/helppc/bios_data_area.html for a
   description of the BIOS Data Area layout.  */
struct grub_machine_bios_data_area
{
  grub_uint8_t unused1[0x17];
  grub_uint8_t keyboard_flag_lower; /* 0x17 */
  grub_uint8_t unused2[0xf0 - 0x18];
};

grub_err_t grub_machine_mmap_register (grub_uint64_t start, grub_uint64_t size,
				       int type, int handle);
grub_err_t grub_machine_mmap_unregister (int handle);

#endif

#endif /* ! GRUB_MEMORY_MACHINE_HEADER */
