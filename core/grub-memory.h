#ifndef GRUB_MEMORY_H
#define GRUB_MEMORY_H

#include "core/grub-types.h"
#include "core/grub-err.h"

typedef enum grub_memory_type
  {
    GRUB_MEMORY_AVAILABLE = 1,
    GRUB_MEMORY_RESERVED = 2,
    GRUB_MEMORY_ACPI = 3,
    GRUB_MEMORY_NVS = 4,
    GRUB_MEMORY_BADRAM = 5,
    GRUB_MEMORY_PERSISTENT = 7,
    GRUB_MEMORY_PERSISTENT_LEGACY = 12,
    GRUB_MEMORY_COREBOOT_TABLES = 16,
    GRUB_MEMORY_CODE = 20,
    /* This one is special: it's used internally but is never reported
       by firmware. Don't use -1 as it's used internally for other purposes. */
    GRUB_MEMORY_HOLE = -2,
    GRUB_MEMORY_MAX = 0x10000
  } grub_memory_type_t;

typedef int (*grub_memory_hook_t) (grub_uint64_t,
				   grub_uint64_t,
				   grub_memory_type_t,
				   void *);

grub_err_t grub_mmap_iterate (grub_memory_hook_t hook, void *hook_data);

#ifdef GRUB_MACHINE_EFI
grub_err_t
grub_efi_mmap_iterate (grub_memory_hook_t hook, void *hook_data,
		       int avoid_efi_boot_services);
#endif

#if !defined (GRUB_MACHINE_EMU) && !defined (GRUB_MACHINE_EFI)
grub_err_t EXPORT_FUNC(grub_machine_mmap_iterate) (grub_memory_hook_t hook,
						   void *hook_data);
#else
grub_err_t grub_machine_mmap_iterate (grub_memory_hook_t hook,
				      void *hook_data);
#endif

int grub_mmap_register (grub_uint64_t start, grub_uint64_t size, int type);
grub_err_t grub_mmap_unregister (int handle);

void *grub_mmap_malign_and_register (grub_uint64_t align, grub_uint64_t size,
				     int *handle, int type, int flags);

void grub_mmap_free_and_unregister (int handle);

#ifndef GRUB_MMAP_REGISTER_BY_FIRMWARE

struct grub_mmap_region
{
  struct grub_mmap_region *next;
  grub_uint64_t start;
  grub_uint64_t end;
  grub_memory_type_t type;
  int handle;
  int priority;
};

extern struct grub_mmap_region *grub_mmap_overlays;
#endif

#endif /* ! GRUB_MEMORY_HEADER */
