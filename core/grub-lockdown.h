#ifndef GRUB_LOCKDOWN_H
#define GRUB_LOCKDOWN_H

#include "core/grub-symbol.h"

#define GRUB_LOCKDOWN_DISABLED       0
#define GRUB_LOCKDOWN_ENABLED        1

#ifdef GRUB_MACHINE_EFI
extern void
EXPORT_FUNC (grub_lockdown) (void);
extern int
EXPORT_FUNC (grub_is_lockdown) (void);
#else
static inline void
grub_lockdown (void)
{
}

static inline int
grub_is_lockdown (void)
{
  return GRUB_LOCKDOWN_DISABLED;
}
#endif
#endif /* ! GRUB_LOCKDOWN_H */
