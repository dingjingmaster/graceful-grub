#ifndef GRUB_OFFSETS_H
#define GRUB_OFFSETS_H

#include "core/grub-types.h"

/* The offset of GRUB_COMPRESSED_SIZE.  */
#define GRUB_DECOMPRESSOR_I386_PC_COMPRESSED_SIZE	0x08

/* The offset of GRUB_COMPRESSED_SIZE.  */
#define GRUB_DECOMPRESSOR_I386_PC_UNCOMPRESSED_SIZE	0x0c

/* Offset of reed_solomon_redundancy.  */
#define GRUB_KERNEL_I386_PC_REED_SOLOMON_REDUNDANCY	0x10

/* Offset of field holding no reed solomon length.  */
#define GRUB_KERNEL_I386_PC_NO_REED_SOLOMON_LENGTH      0x14

#define GRUB_DECOMPRESSOR_I386_PC_BOOT_DEVICE           0x18

#define GRUB_DECOMPRESSOR_I386_PC_MAX_DECOMPRESSOR_SIZE (0x9000-0x8200)

/* The segment where the kernel is loaded.  */
#define GRUB_BOOT_I386_PC_KERNEL_SEG		0x800

#define GRUB_KERNEL_I386_PC_LINK_ADDR		0x9000
#define GRUB_KERNEL_I386_XEN_PVH_LINK_ADDR	0x100000

/* The upper memory area (starting at 640 kiB).  */
#define GRUB_MEMORY_I386_PC_UPPER		0xa0000
#define GRUB_MEMORY_I386_QEMU_UPPER		GRUB_MEMORY_I386_PC_UPPER

/* The offset of GRUB_CORE_ENTRY_ADDR.  */
#define GRUB_BOOT_I386_QEMU_CORE_ENTRY_ADDR	0x4

/* The offset of GRUB_CORE_ENTRY_ADDR.  */
#define GRUB_KERNEL_I386_QEMU_CORE_ENTRY_ADDR	0x8

#define GRUB_KERNEL_I386_QEMU_LINK_ADDR         0x9000

/* The offset of GRUB_TOTAL_MODULE_SIZE.  */
#define GRUB_KERNEL_SPARC64_IEEE1275_TOTAL_MODULE_SIZE	0x8
#define GRUB_KERNEL_ARM_STACK_SIZE 0x40000

#define GRUB_BOOT_SPARC64_IEEE1275_LIST_SIZE	12

#define GRUB_BOOT_SPARC64_IEEE1275_IMAGE_ADDRESS	0x4400
#define GRUB_KERNEL_SPARC64_IEEE1275_LINK_ADDR 0x4400

#define GRUB_KERNEL_POWERPC_IEEE1275_LINK_ALIGN 4
#define GRUB_KERNEL_POWERPC_IEEE1275_LINK_ADDR 0x200000

#define GRUB_KERNEL_MIPS_LOONGSON_LINK_ADDR         0x80200000

#define GRUB_KERNEL_MIPS_LOONGSON_LINK_ALIGN  32

#define GRUB_DECOMPRESSOR_MIPS_LOONGSON_COMPRESSED_SIZE          0x8
#define GRUB_DECOMPRESSOR_MIPS_LOONGSON_UNCOMPRESSED_SIZE        0xc
#define GRUB_DECOMPRESSOR_MIPS_LOONGSON_UNCOMPRESSED_ADDR        0x10

#define GRUB_KERNEL_MIPS_LOONGSON_TOTAL_MODULE_SIZE	0x08

#define GRUB_KERNEL_MIPS_QEMU_MIPS_LINK_ADDR         0x80200000
#define GRUB_KERNEL_MIPS_QEMU_MIPS_LINK_ALIGN  32
#define GRUB_DECOMPRESSOR_MIPS_QEMU_MIPS_COMPRESSED_SIZE          0x8
#define GRUB_DECOMPRESSOR_MIPS_QEMU_MIPS_UNCOMPRESSED_SIZE        0xc
#define GRUB_DECOMPRESSOR_MIPS_QEMU_MIPS_UNCOMPRESSED_ADDR        0x10
#define GRUB_KERNEL_MIPS_QEMU_MIPS_TOTAL_MODULE_SIZE	0x08

#define GRUB_KERNEL_MIPS_ARC_LINK_ADDR         0x88200000
#define GRUB_KERNEL_MIPSEL_ARC_LINK_ADDR         0x80700000
#define GRUB_KERNEL_MIPS_ARC_LINK_ALIGN  32

#define GRUB_DECOMPRESSOR_MIPS_ARC_COMPRESSED_SIZE          0x8
#define GRUB_DECOMPRESSOR_MIPS_ARC_UNCOMPRESSED_SIZE        0xc
#define GRUB_DECOMPRESSOR_MIPS_ARC_UNCOMPRESSED_ADDR        0x10

#define GRUB_KERNEL_MIPS_ARC_TOTAL_MODULE_SIZE	0x08

#define GRUB_KERNEL_I386_COREBOOT_LINK_ADDR	0x9000
#define GRUB_KERNEL_I386_COREBOOT_MODULES_ADDR  0x100000

#define GRUB_KERNEL_I386_IEEE1275_LINK_ADDR	0x10000

#define GRUB_KERNEL_I386_IEEE1275_MOD_ALIGN	0x1000
#define GRUB_KERNEL_I386_COREBOOT_MOD_ALIGN	0x1
#define GRUB_KERNEL_I386_MULTIBOOT_MOD_ALIGN	GRUB_KERNEL_I386_COREBOOT_MOD_ALIGN

#define GRUB_KERNEL_X86_64_XEN_MOD_ALIGN	0x8
#define GRUB_KERNEL_I386_XEN_MOD_ALIGN		0x8
#define GRUB_KERNEL_I386_XEN_PVH_MOD_ALIGN	0x8

/* Non-zero value is only needed for PowerMacs.  */
#define GRUB_KERNEL_X86_64_XEN_MOD_GAP		0x0
#define GRUB_KERNEL_I386_XEN_MOD_GAP		0x0
#define GRUB_KERNEL_I386_XEN_PVH_MOD_GAP	0x0
#define GRUB_KERNEL_I386_IEEE1275_MOD_GAP	0x0
#define GRUB_KERNEL_I386_COREBOOT_MOD_GAP	0x0
#define GRUB_KERNEL_SPARC64_IEEE1275_MOD_GAP	0x0
#define GRUB_KERNEL_ARM_UBOOT_MOD_GAP		0x0

#define GRUB_KERNEL_POWERPC_IEEE1275_MOD_ALIGN 0x1000
#define GRUB_KERNEL_SPARC64_IEEE1275_LOG_MOD_ALIGN 3
#define GRUB_KERNEL_SPARC64_IEEE1275_MOD_ALIGN (1 << GRUB_KERNEL_SPARC64_IEEE1275_LOG_MOD_ALIGN)

#define GRUB_KERNEL_MIPS_LOONGSON_MOD_ALIGN 0x1
#define GRUB_KERNEL_MIPS_ARC_MOD_ALIGN 0x1
#define GRUB_KERNEL_MIPS_QEMU_MIPS_MOD_ALIGN 0x1

#define GRUB_KERNEL_ARM_UBOOT_MOD_ALIGN 	0x8
#define GRUB_KERNEL_ARM_UBOOT_TOTAL_MODULE_SIZE	0x4

#define GRUB_KERNEL_ARM_COREBOOT_MOD_ALIGN 	0x8
#define GRUB_KERNEL_ARM_COREBOOT_TOTAL_MODULE_SIZE	0x4

#define GRUB_KERNEL_ARM_STACK_SIZE 0x40000
#define GRUB_KERNEL_ARM_COREBOOT_MOD_GAP (GRUB_KERNEL_ARM_STACK_SIZE + 1024)

/* Minimal gap between _end and the start of the modules.  It's a hack
   for PowerMac to prevent "CLAIM failed" error.  The real fix is to
   rewrite grub-mkimage to generate valid ELF files.  */
#define GRUB_KERNEL_POWERPC_IEEE1275_MOD_GAP 0x8000

#ifdef GRUB_MACHINE
#define GRUB_OFFSETS_CONCAT_(a,b,c) a ## b ## c
#define GRUB_OFFSETS_CONCAT(a,b,c) GRUB_OFFSETS_CONCAT_(a,b,c)
#define GRUB_KERNEL_MACHINE_MOD_ALIGN GRUB_OFFSETS_CONCAT (GRUB_KERNEL_, GRUB_MACHINE, _MOD_ALIGN)
#define GRUB_KERNEL_MACHINE_MOD_GAP GRUB_OFFSETS_CONCAT (GRUB_KERNEL_, GRUB_MACHINE, _MOD_GAP)
#define GRUB_KERNEL_MACHINE_TOTAL_MODULE_SIZE GRUB_OFFSETS_CONCAT (GRUB_KERNEL_, GRUB_MACHINE, _TOTAL_MODULE_SIZE)

#define GRUB_BOOT_MACHINE_KERNEL_SEG GRUB_OFFSETS_CONCAT (GRUB_BOOT_, GRUB_MACHINE, _KERNEL_SEG)
#define GRUB_MEMORY_MACHINE_UPPER GRUB_OFFSETS_CONCAT (GRUB_MEMORY_, GRUB_MACHINE, _UPPER)
#if defined (GRUB_MACHINE_ARC) && defined (GRUB_CPU_MIPSEL)
#define GRUB_MACHINE_LINK_ADDR GRUB_KERNEL_MIPSEL_ARC_LINK_ADDR
#else
#define GRUB_MACHINE_LINK_ADDR GRUB_OFFSETS_CONCAT (GRUB_KERNEL_, GRUB_MACHINE, _LINK_ADDR)
#endif

#define GRUB_DECOMPRESSOR_MACHINE_COMPRESSED_SIZE GRUB_OFFSETS_CONCAT (GRUB_DECOMPRESSOR_, GRUB_MACHINE, _COMPRESSED_SIZE)
#define GRUB_DECOMPRESSOR_MACHINE_UNCOMPRESSED_SIZE GRUB_OFFSETS_CONCAT (GRUB_DECOMPRESSOR_, GRUB_MACHINE, _UNCOMPRESSED_SIZE)
#define GRUB_DECOMPRESSOR_MACHINE_UNCOMPRESSED_ADDR GRUB_OFFSETS_CONCAT (GRUB_DECOMPRESSOR_, GRUB_MACHINE, _UNCOMPRESSED_ADDR)
#endif

#ifndef ASM_FILE
struct grub_pc_bios_boot_blocklist
{
  grub_uint64_t start;
  grub_uint16_t len;
  grub_uint16_t segment;
} GRUB_PACKED;
#endif

#endif
