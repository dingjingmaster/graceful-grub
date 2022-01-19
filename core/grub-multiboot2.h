#ifndef GRUB_MULTIBOOT2_H
#define GRUB_MULTIBOOT2_H

#include "core/grub-file.h"

//#include <multiboot2.h>

#include "core/grub-types.h"
#include "core/grub-err.h"

extern struct grub_relocator *grub_multiboot2_relocator;

void grub_multiboot2 (int argc, char *argv[]);
void grub_module2 (int argc, char *argv[]);

void grub_multiboot2_set_accepts_video (int val);
grub_err_t grub_multiboot2_make_mbi (grub_uint32_t *target);
void grub_multiboot2_free_mbi (void);
grub_err_t grub_multiboot2_init_mbi (int argc, char *argv[]);
grub_err_t grub_multiboot2_add_module (grub_addr_t start, grub_size_t size,
				      int argc, char *argv[]);
void grub_multiboot2_set_bootdev (void);
void
grub_multiboot2_add_elfsyms (grub_size_t num, grub_size_t entsize,
			    unsigned shndx, void *data);

grub_uint32_t grub_multiboot2_get_mmap_count (void);
grub_err_t grub_multiboot2_set_video_mode (void);

/* FIXME: support coreboot as well.  */
#if defined (GRUB_MACHINE_PCBIOS)
#define GRUB_MACHINE_HAS_VBE 1
#else
#define GRUB_MACHINE_HAS_VBE 0
#endif

#if defined (GRUB_MACHINE_PCBIOS) || defined (GRUB_MACHINE_COREBOOT) || defined (GRUB_MACHINE_MULTIBOOT) || defined (GRUB_MACHINE_QEMU)
#define GRUB_MACHINE_HAS_VGA_TEXT 1
#else
#define GRUB_MACHINE_HAS_VGA_TEXT 0
#endif

#if defined (GRUB_MACHINE_EFI) || defined (GRUB_MACHINE_PCBIOS) || defined (GRUB_MACHINE_COREBOOT) || defined (GRUB_MACHINE_MULTIBOOT)
#define GRUB_MACHINE_HAS_ACPI 1
#else
#define GRUB_MACHINE_HAS_ACPI 0
#endif

#define GRUB_MULTIBOOT2_CONSOLE_EGA_TEXT 1
#define GRUB_MULTIBOOT2_CONSOLE_FRAMEBUFFER 2 

grub_err_t
grub_multiboot2_set_console (int console_type, int accepted_consoles,
			    int width, int height, int depth,
			    int console_required);
grub_err_t
grub_multiboot2_load (grub_file_t file, const char *filename);

struct mbi_load_data
{
  grub_file_t file;
  const char *filename;
  void *buffer;
  unsigned int mbi_ver;
  int relocatable;
  grub_uint32_t min_addr;
  grub_uint32_t max_addr;
  grub_size_t align;
  grub_uint32_t preference;
  grub_uint32_t link_base_addr;
  grub_uint32_t load_base_addr;
  int avoid_efi_boot_services;
};
typedef struct mbi_load_data mbi_load_data_t;

/* Load ELF32 or ELF64.  */
grub_err_t
grub_multiboot2_load_elf (mbi_load_data_t *mld);

extern grub_size_t grub_multiboot2_pure_size;
extern grub_size_t grub_multiboot2_alloc_mbi;
extern grub_uint32_t grub_multiboot2_payload_eip;


#endif /* ! GRUB_MULTIBOOT_HEADER */
