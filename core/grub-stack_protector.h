#ifndef GRUB_STACK_PROTECTOR_H
#define GRUB_STACK_PROTECTOR_H

#include "grub-symbol.h"
#include "grub-types.h"

#ifdef GRUB_STACK_PROTECTOR
extern grub_addr_t EXPORT_VAR (__stack_chk_guard);
extern void __attribute__ ((noreturn)) EXPORT_FUNC (__stack_chk_fail) (void);
#endif

#endif /* GRUB_STACK_PROTECTOR_H */
