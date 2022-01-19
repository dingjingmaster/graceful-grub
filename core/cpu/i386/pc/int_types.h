#ifndef GRUB_INTERRUPT_TYPES_MACHINE_H
#define GRUB_INTERRUPT_TYPES_MACHINE_H

#include "core/grub-types.h"

#define  GRUB_CPU_INT_FLAGS_CARRY     0x1
#define  GRUB_CPU_INT_FLAGS_PARITY    0x4
#define  GRUB_CPU_INT_FLAGS_ADJUST    0x10
#define  GRUB_CPU_INT_FLAGS_ZERO      0x40
#define  GRUB_CPU_INT_FLAGS_SIGN      0x80
#define  GRUB_CPU_INT_FLAGS_TRAP      0x100
#define  GRUB_CPU_INT_FLAGS_INTERRUPT 0x200
#define  GRUB_CPU_INT_FLAGS_DIRECTION 0x400
#define  GRUB_CPU_INT_FLAGS_OVERFLOW  0x800
#ifdef GRUB_MACHINE_PCBIOS
#define  GRUB_CPU_INT_FLAGS_DEFAULT   GRUB_CPU_INT_FLAGS_INTERRUPT
#else
#define  GRUB_CPU_INT_FLAGS_DEFAULT   0
#endif

struct grub_bios_int_registers
{
  grub_uint32_t eax;
  grub_uint16_t es;
  grub_uint16_t ds;
  grub_uint16_t flags;
  grub_uint16_t dummy;
  grub_uint32_t ebx;
  grub_uint32_t ecx;
  grub_uint32_t edi;
  grub_uint32_t esi;
  grub_uint32_t edx;
};

struct grub_i386_idt
{
  grub_uint16_t limit;
  grub_uint32_t base;
} GRUB_PACKED;

#endif
