#ifndef GRUB_UTIL_MISC_H
#define GRUB_UTIL_MISC_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include <unistd.h>

#include "config.h"
#include "core/grub-types.h"
#include "core/grub-symbol.h"
#include "core/emu/misc.h"

char *grub_util_get_path (const char *dir, const char *file);
size_t grub_util_get_image_size (const char *path);
char *grub_util_read_image (const char *path);
void grub_util_load_image (const char *path, char *buf);
void grub_util_write_image (const char *img, size_t size, FILE *out,
			    const char *name);
void grub_util_write_image_at (const void *img, size_t size, off_t offset,
			       FILE *out, const char *name);

char *make_system_path_relative_to_its_root (const char *path);

char *grub_canonicalize_file_name (const char *path);

void grub_util_init_nls (void);

void grub_util_host_init (int *argc, char ***argv);

int grub_qsort_strcmp (const void *, const void *);

#endif /* ! GRUB_UTIL_MISC_HEADER */
