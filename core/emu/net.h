#ifndef GRUB_EMUNET_HEADER
#define GRUB_EMUNET_HEADER

#include "core/grub-types.h"
#include "core/grub-symbol.h"

grub_ssize_t
EXPORT_FUNC(grub_emunet_send) (const void *packet, grub_size_t sz);

grub_ssize_t
EXPORT_FUNC(grub_emunet_receive) (void *packet, grub_size_t sz);

int
EXPORT_FUNC(grub_emunet_create) (grub_size_t *mtu);

void
EXPORT_FUNC(grub_emunet_close) (void);

#endif
