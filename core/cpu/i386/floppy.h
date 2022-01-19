#ifndef GRUB_FLOPPY_CPU_H
#define GRUB_FLOPPY_CPU_H

#define GRUB_FLOPPY_REG_DIGITAL_OUTPUT		0x3f2

#ifndef ASM_FILE
#include "core/cpu/io.h"

/* Stop the floppy drive from spinning, so that other software is
   jumped to with a known state.  */
static inline void
grub_stop_floppy (void)
{
  grub_outb (0, GRUB_FLOPPY_REG_DIGITAL_OUTPUT);
}
#endif

#endif
