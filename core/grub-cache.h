#ifndef GRUB_CACHE_H
#define GRUB_CACHE_H

#include "core/grub-symbol.h"
#include "core/grub-types.h"

#if defined (__i386__) || defined (__x86_64__)
static inline void
grub_arch_sync_caches (void *address __attribute__ ((unused)),
		       grub_size_t len __attribute__ ((unused)))
{
}
#else
void EXPORT_FUNC(grub_arch_sync_caches) (void *address, grub_size_t len);
#endif

#ifndef GRUB_MACHINE_EMU
#if defined (__aarch64__) || defined (__ia64__) || defined (__powerpc__) || \
    defined (__sparc__)

#elif defined (__i386__) || defined (__x86_64__)
static inline void
grub_arch_sync_dma_caches (volatile void *address __attribute__ ((unused)),
			   grub_size_t len __attribute__ ((unused)))
{
}
#else
void EXPORT_FUNC(grub_arch_sync_dma_caches) (volatile void *address, grub_size_t len);
#endif
#endif

#ifdef __arm__
void
grub_arm_cache_enable (void);
#endif

#endif /* ! GRUB_CACHE_HEADER */
