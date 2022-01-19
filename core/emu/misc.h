#ifndef GRUB_EMU_MISC_H
#define GRUB_EMU_MISC_H

#include "../../config.h"
#include <stdarg.h>

#include <stdio.h>

#include "../grub-compiler.h"
#include "../grub-symbol.h"
#include "../grub-types.h"
#include "../grub-misc.h"
#include "../util/misc.h"

extern int verbosity;
extern const char *program_name;

void grub_init_all (void);
void grub_fini_all (void);

void grub_find_zpool_from_dir (const char *dir,
			       char **poolname, char **poolfs);

char *grub_make_system_path_relative_to_its_root (const char *path)
 WARN_UNUSED_RESULT;
int
grub_util_device_is_mapped (const char *dev);

#define GRUB_HOST_PRIuLONG_LONG "llu"
#define GRUB_HOST_PRIxLONG_LONG "llx"

void * EXPORT_FUNC(xcalloc) (grub_size_t nmemb, grub_size_t size) WARN_UNUSED_RESULT;
void * EXPORT_FUNC(xmalloc) (grub_size_t size) WARN_UNUSED_RESULT;
void * EXPORT_FUNC(xrealloc) (void *ptr, grub_size_t size) WARN_UNUSED_RESULT;
char * EXPORT_FUNC(xstrdup) (const char *str) WARN_UNUSED_RESULT;
char * EXPORT_FUNC(xasprintf) (const char *fmt, ...) __attribute__ ((format (GNU_PRINTF, 1, 2))) WARN_UNUSED_RESULT;

void EXPORT_FUNC(grub_util_warn) (const char *fmt, ...) __attribute__ ((format (GNU_PRINTF, 1, 2)));
void EXPORT_FUNC(grub_util_info) (const char *fmt, ...) __attribute__ ((format (GNU_PRINTF, 1, 2)));
void EXPORT_FUNC(grub_util_error) (const char *fmt, ...) __attribute__ ((format (GNU_PRINTF, 1, 2), noreturn));

grub_uint64_t EXPORT_FUNC (grub_util_get_cpu_time_ms) (void);

#ifdef HAVE_DEVICE_MAPPER
int grub_device_mapper_supported (void);
#endif

#ifdef GRUB_BUILD
#define grub_util_fopen fopen
#else
FILE *
grub_util_fopen (const char *path, const char *mode);
#endif

int grub_util_file_sync (FILE *f);

#endif /* GRUB_EMU_MISC_H */
