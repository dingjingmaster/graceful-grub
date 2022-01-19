#ifndef GRUB_CONSOLE_MACHINE_H
#define GRUB_CONSOLE_MACHINE_H

#ifndef ASM_FILE

#include "core/grub-types.h"
#include "core/grub-symbol.h"
#include "core/grub-term.h"

/* Initialize the console system.  */
void grub_console_init (void);

/* Finish the console system.  */
void grub_console_fini (void);

#endif

#endif /* ! GRUB_CONSOLE_MACHINE_HEADER */
