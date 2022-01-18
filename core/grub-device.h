#ifndef GRUBDEVICE_H
#define GRUBDEVICE_H

#include "grub-symbol.h"
#include "grub-err.h"

struct grub_disk;
struct grub_net;

struct grub_device
{
    struct grub_disk *disk;
    struct grub_net *net;
};

typedef struct grub_device *grub_device_t;

typedef int (*grub_device_iterate_hook_t) (const char *name, void *data);

grub_device_t EXPORT_FUNC(grub_device_open) (const char *name);
grub_err_t EXPORT_FUNC(grub_device_close) (grub_device_t device);
int EXPORT_FUNC(grub_device_iterate) (grub_device_iterate_hook_t hook, void *hook_data);

#endif // GRUBDEVICE_H
