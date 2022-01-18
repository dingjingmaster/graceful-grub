#ifndef GRUB_AUTOEFI_H
#define GRUB_AUTOEFI_H


#ifdef GRUB_MACHINE_EFI
# include <grub/efi/efi.h>
# define grub_autoefi_get_memory_map grub_efi_get_memory_map
# define grub_autoefi_finish_boot_services grub_efi_finish_boot_services
# define grub_autoefi_exit_boot_services grub_efi_exit_boot_services
# define grub_autoefi_system_table grub_efi_system_table
# define grub_autoefi_mmap_iterate grub_machine_mmap_iterate
# define grub_autoefi_set_virtual_address_map grub_efi_set_virtual_address_map
static inline grub_err_t grub_autoefi_prepare (void)
{
  return GRUB_ERR_NONE;
};
# define SYSTEM_TABLE_SIZEOF(x) (sizeof(grub_efi_system_table->x))
# define SYSTEM_TABLE_VAR(x) ((void *)&(grub_efi_system_table->x))
# define SYSTEM_TABLE_PTR(x) ((void *)(grub_efi_system_table->x))
# define SIZEOF_OF_UINTN sizeof (grub_efi_uintn_t)
# define SYSTEM_TABLE(x) (grub_efi_system_table->x)
# define grub_autoefi_finish_boot_services grub_efi_finish_boot_services
# define EFI_PRESENT 1
#else
# include "core/efiemu/efiemu.h"
# define grub_autoefi_get_memory_map grub_efiemu_get_memory_map
# define grub_autoefi_finish_boot_services grub_efiemu_finish_boot_services
# define grub_autoefi_exit_boot_services grub_efiemu_exit_boot_services
# define grub_autoefi_system_table grub_efiemu_system_table
# define grub_autoefi_mmap_iterate grub_efiemu_mmap_iterate
# define grub_autoefi_prepare grub_efiemu_prepare
# define grub_autoefi_set_virtual_address_map grub_efiemu_set_virtual_address_map
# define SYSTEM_TABLE_SIZEOF GRUB_EFIEMU_SYSTEM_TABLE_SIZEOF
# define SYSTEM_TABLE_VAR GRUB_EFIEMU_SYSTEM_TABLE_VAR
# define SYSTEM_TABLE_PTR GRUB_EFIEMU_SYSTEM_TABLE_PTR
# define SIZEOF_OF_UINTN GRUB_EFIEMU_SIZEOF_OF_UINTN
# define SYSTEM_TABLE GRUB_EFIEMU_SYSTEM_TABLE
# define grub_efi_allocate_fixed(x,y) (x)
# define grub_efi_free_pages(x,y) GRUB_EFI_SUCCESS
# define grub_autoefi_finish_boot_services grub_efiemu_finish_boot_services
# define EFI_PRESENT 1
#endif

#endif
