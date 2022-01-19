#ifndef KERNEL_CPU_TSC_H
#define KERNEL_CPU_TSC_H

#include "core/grub-types.h"
#include "core/cpu/i386/cpuid.h"

void grub_tsc_init (void);
/* In ms per 2^32 ticks.  */
extern grub_uint32_t EXPORT_VAR(grub_tsc_rate);
int
grub_tsc_calibrate_from_xen (void);
int
grub_tsc_calibrate_from_efi (void);
int
grub_tsc_calibrate_from_pmtimer (void);
int
grub_tsc_calibrate_from_pit (void);

/* Read the TSC value, which increments with each CPU clock cycle. */
static __inline grub_uint64_t
grub_get_tsc (void)
{
  grub_uint32_t lo, hi;
  grub_uint32_t a,b,c,d;

  /* The CPUID instruction is a 'serializing' instruction, and
     avoids out-of-order execution of the RDTSC instruction. */
  grub_cpuid (0,a,b,c,d);
  /* Read TSC value.  We cannot use "=A", since this would use
     %rax on x86_64. */
  asm volatile ("rdtsc":"=a" (lo), "=d" (hi));

  return (((grub_uint64_t) hi) << 32) | lo;
}

static __inline int
grub_cpu_is_tsc_supported (void)
{
#if !defined(GRUB_MACHINE_XEN) && !defined(GRUB_MACHINE_XEN_PVH)
  grub_uint32_t a,b,c,d;
  if (! grub_cpu_is_cpuid_supported ())
    return 0;

  grub_cpuid(1,a,b,c,d);

  return (d & (1 << 4)) != 0;
#else
  return 1;
#endif
}

#endif /* ! KERNEL_CPU_TSC_HEADER */
