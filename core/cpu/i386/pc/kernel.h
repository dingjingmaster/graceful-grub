#ifndef KERNEL_MACHINE_H
#define KERNEL_MACHINE_H

#include "core/grub-offsets.h"

/* Enable LZMA compression */
#define ENABLE_LZMA	1

#ifndef ASM_FILE

#include "core/grub-symbol.h"
#include "core/grub-types.h"

/* The total size of module images following the kernel.  */
extern grub_int32_t grub_total_module_size;

extern grub_uint32_t EXPORT_VAR(grub_boot_device);

extern void (*EXPORT_VAR(grub_pc_net_config)) (char **device, char **path);

#endif /* ! ASM_FILE */

#endif /* ! KERNEL_MACHINE_HEADER */
