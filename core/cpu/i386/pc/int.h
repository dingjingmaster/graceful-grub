#ifndef GRUB_INTERRUPT_MACHINE_H
#define GRUB_INTERRUPT_MACHINE_H

#include "core/grub-symbol.h"
#include "int_types.h"

void EXPORT_FUNC (grub_bios_interrupt) (grub_uint8_t intno,
					struct grub_bios_int_registers *regs)
     __attribute__ ((regparm(3)));

#ifdef GRUB_MACHINE_PCBIOS
extern struct grub_i386_idt *EXPORT_VAR(grub_realidt);
#endif

#endif
