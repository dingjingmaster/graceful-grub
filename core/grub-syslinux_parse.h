#ifndef GRUB_SYSLINUX_PARSE_H
#define GRUB_SYSLINUX_PARSE_H

#include "grub-types.h"

typedef enum
  {
    GRUB_SYSLINUX_UNKNOWN,
    GRUB_SYSLINUX_ISOLINUX,
    GRUB_SYSLINUX_PXELINUX,
    GRUB_SYSLINUX_SYSLINUX,
  } grub_syslinux_flavour_t;

char *
grub_syslinux_config_file (const char *root, const char *target_root,
			   const char *cwd, const char *target_cwd,
			   const char *fname, grub_syslinux_flavour_t flav);

#endif
