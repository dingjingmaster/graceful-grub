#ifndef GRUB_CONFIG_EMU_H
#define GRUB_CONFIG_EMU_H

#include "../../core/grub-disk.h"
#include "../../core/grub-partition.h"
#include "../../core/emu/hostfile.h"
#include <stdio.h>

const char *
grub_util_get_config_filename (void);
const char *
grub_util_get_pkgdatadir (void);
const char *
grub_util_get_pkglibdir (void);
const char *
grub_util_get_localedir (void);

struct grub_util_config
{
  int is_cryptodisk_enabled;
  char *grub_distributor;
};

void
grub_util_load_config (struct grub_util_config *cfg);

void
grub_util_parse_config (FILE *f, struct grub_util_config *cfg, int simple);

#endif
