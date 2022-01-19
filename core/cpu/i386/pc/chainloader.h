#ifndef GRUB_CHAINLOADER_MACHINE_H
#define GRUB_CHAINLOADER_MACHINE_H

#include "core/grub-dl.h"

void
grub_chainloader_patch_bpb (void *bs, grub_device_t dev, grub_uint8_t dl);

#endif /* GRUB_CHAINLOADER_MACHINE_HEADER */
