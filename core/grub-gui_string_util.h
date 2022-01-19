#ifndef GRUB_GUI_STRING_UTIL_H
#define GRUB_GUI_STRING_UTIL_H

#include "grub-types.h"
#include "grub-gui.h"

char *grub_new_substring (const char *buf,
                          grub_size_t start, grub_size_t end);

char *grub_resolve_relative_path (const char *base, const char *path);

char *grub_get_dirname (const char *file_path);

#endif /* GRUB_GUI_STRING_UTIL_HEADER */
