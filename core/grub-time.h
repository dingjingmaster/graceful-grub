#ifndef KERNEL_TIME_H
#define KERNEL_TIME_H

#include "core/grub-types.h"
#include "core/grub-symbol.h"
#if !defined(GRUB_MACHINE_EMU) && !defined(GRUB_UTIL)

// FIXME:// DJ-
#include "core/cpu/i386/time.h"
#else
static inline void
grub_cpu_idle(void)
{
}
#endif

void EXPORT_FUNC(grub_millisleep) (grub_uint32_t ms);
grub_uint64_t EXPORT_FUNC(grub_get_time_ms) (void);

grub_uint64_t grub_rtc_get_time_ms (void);

static __inline void
grub_sleep (grub_uint32_t s)
{
  grub_millisleep (1000 * s);
}

void grub_install_get_time_ms (grub_uint64_t (*get_time_ms_func) (void));

#endif /* ! KERNEL_TIME_HEADER */
