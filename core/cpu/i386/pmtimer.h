#ifndef KERNEL_CPU_PMTIMER_H
#define KERNEL_CPU_PMTIMER_H

#include "core/cpu/i386/tsc.h"
#include "core/cpu/i386/io.h"

/*
  Preconditions:
  * Caller has ensured that both pmtimer and tsc are supported
  * 1 <= num_pm_ticks <= 3580
  Return:
  * Number of TSC ticks elapsed
  * 0 on failure.
*/
grub_uint64_t
EXPORT_FUNC(grub_pmtimer_wait_count_tsc) (grub_port_t pmtimer,
					  grub_uint16_t num_pm_ticks);

#endif
