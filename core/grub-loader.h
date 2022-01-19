#ifndef GRUB_LOADER_H
#define GRUB_LOADER_H

#include "core/grub-file.h"
#include "core/grub-symbol.h"
#include "core/grub-err.h"
#include "core/grub-types.h"

/* Check if a loader is loaded.  */
int EXPORT_FUNC (grub_loader_is_loaded) (void);

/* Set loader functions.  */
enum
{
  GRUB_LOADER_FLAG_NORETURN = 1,
  GRUB_LOADER_FLAG_PXE_NOT_UNLOAD = 2,
  GRUB_LOADER_FLAG_EFI_KEEP_ALLOCATED_MEMORY = 4,
};

void EXPORT_FUNC (grub_loader_set) (grub_err_t (*boot) (void),
				    grub_err_t (*unload) (void),
				    int flags);

/* Unset current loader, if any.  */
void EXPORT_FUNC (grub_loader_unset) (void);

/* Call the boot hook in current loader. This may or may not return,
   depending on the setting by grub_loader_set.  */
grub_err_t grub_loader_boot (void);

/* The space between numbers is intentional for the simplicity of adding new
   values even if external modules use them. */
typedef enum {
  /* A preboot hook which can use everything and turns nothing off. */
  GRUB_LOADER_PREBOOT_HOOK_PRIO_NORMAL = 400,
  /* A preboot hook which can't use disks and may stop disks. */
  GRUB_LOADER_PREBOOT_HOOK_PRIO_DISK = 300,
  /* A preboot hook which can't use disks or console and may stop console. */
  GRUB_LOADER_PREBOOT_HOOK_PRIO_CONSOLE = 200,
  /* A preboot hook which can't use disks or console, can't modify memory map
     and may stop memory services or finalize memory map. */
  GRUB_LOADER_PREBOOT_HOOK_PRIO_MEMORY = 100,
} grub_loader_preboot_hook_prio_t;

/* Register a preboot hook. */
struct grub_preboot;

struct grub_preboot *EXPORT_FUNC(grub_loader_register_preboot_hook) (grub_err_t (*preboot_func) (int noret),
								     grub_err_t (*preboot_rest_func) (void),
								     grub_loader_preboot_hook_prio_t prio);

/* Unregister given preboot hook. */
void EXPORT_FUNC (grub_loader_unregister_preboot_hook) (struct grub_preboot *hnd);

#ifndef GRUB_MACHINE_EMU
void grub_boot_init (void);
void grub_boot_fini (void);
#endif

#endif /* ! GRUB_LOADER_HEADER */
