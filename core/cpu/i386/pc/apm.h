#ifndef GRUB_APM_MACHINE_H
#define GRUB_APM_MACHINE_H

#include "core/grub-types.h"

struct grub_apm_info
{
  grub_uint16_t cseg;
  grub_uint32_t offset;
  grub_uint16_t cseg_16;
  grub_uint16_t dseg;
  grub_uint16_t flags;
  grub_uint16_t cseg_len;
  grub_uint16_t cseg_16_len;
  grub_uint16_t dseg_len;
  grub_uint16_t version;
};

enum
  {
    GRUB_APM_FLAGS_16BITPROTECTED_SUPPORTED = 1,
    GRUB_APM_FLAGS_32BITPROTECTED_SUPPORTED = 2,
    GRUB_APM_FLAGS_CPUIDLE_SLOWS_DOWN = 4,
    GRUB_APM_FLAGS_DISABLED = 8,
    GRUB_APM_FLAGS_DISENGAGED = 16,
  };

int grub_apm_get_info (struct grub_apm_info *info);

#endif
