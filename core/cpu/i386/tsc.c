#include "core/grub-types.h"
#include "core/grub-time.h"
#include "core/grub-misc.h"
#include "core/cpu/i386/tsc.h"
#include "core/cpu/i386/cpuid.h"

/* This defines the value TSC had at the epoch (that is, when we calibrated it). */
static grub_uint64_t tsc_boot_time;

/* Calibrated TSC rate.  (In ms per 2^32 ticks) */
/* We assume that the tick is less than 1 ms and hence this value fits
   in 32-bit.  */
grub_uint32_t grub_tsc_rate;

static grub_uint64_t
grub_tsc_get_time_ms (void)
{
  grub_uint64_t a = grub_get_tsc () - tsc_boot_time;
  grub_uint64_t ah = a >> 32;
  grub_uint64_t al = a & 0xffffffff;

  return ((al * grub_tsc_rate) >> 32) + ah * grub_tsc_rate;
}

static int
calibrate_tsc_hardcode (void)
{
  grub_tsc_rate = 5368;/* 800 MHz */
  return 1;
}

void
grub_tsc_init (void)
{
  if (!grub_cpu_is_tsc_supported ())
    {
#if defined (GRUB_MACHINE_PCBIOS) || defined (GRUB_MACHINE_IEEE1275)
      grub_install_get_time_ms (grub_rtc_get_time_ms);
#else
      grub_fatal ("no TSC found");
#endif
      return;
    }

  tsc_boot_time = grub_get_tsc ();

#if defined (GRUB_MACHINE_XEN) || defined (GRUB_MACHINE_XEN_PVH)
  (void) (grub_tsc_calibrate_from_xen () || calibrate_tsc_hardcode());
#elif defined (GRUB_MACHINE_EFI)
  (void) (grub_tsc_calibrate_from_pmtimer () || grub_tsc_calibrate_from_pit () || grub_tsc_calibrate_from_efi() || calibrate_tsc_hardcode());
#elif defined (GRUB_MACHINE_COREBOOT)
  (void) (grub_tsc_calibrate_from_pmtimer () || grub_tsc_calibrate_from_pit () || calibrate_tsc_hardcode());
#else
  (void) (grub_tsc_calibrate_from_pit () || calibrate_tsc_hardcode());
#endif
  grub_install_get_time_ms (grub_tsc_get_time_ms);
}
