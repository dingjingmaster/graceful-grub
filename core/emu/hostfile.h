#ifndef GRUB_HOSTFILE_EMU_H
#define GRUB_HOSTFILE_EMU_H


#include <sys/types.h>

#include "core/grub-disk.h"
#include "core/grub-partition.h"
#include "core/osdep/hostfile.h"

int
grub_util_is_directory (const char *path);
int
grub_util_is_special_file (const char *path);
int
grub_util_is_regular (const char *path);

char *
grub_util_path_concat (size_t n, ...);
char *
grub_util_path_concat_ext (size_t n, ...);

int
grub_util_fd_seek (grub_util_fd_t fd, grub_uint64_t off);
ssize_t
EXPORT_FUNC(grub_util_fd_read) (grub_util_fd_t fd, char *buf, size_t len);
ssize_t
EXPORT_FUNC(grub_util_fd_write) (grub_util_fd_t fd, const char *buf, size_t len);

grub_util_fd_t
EXPORT_FUNC(grub_util_fd_open) (const char *os_dev, int flags);
const char *
EXPORT_FUNC(grub_util_fd_strerror) (void);
int
grub_util_fd_sync (grub_util_fd_t fd);
void
grub_util_disable_fd_syncs (void);
int
EXPORT_FUNC(grub_util_fd_close) (grub_util_fd_t fd);

grub_uint64_t
grub_util_get_fd_size (grub_util_fd_t fd, const char *name, unsigned *log_secsize);
char *
grub_util_make_temporary_file (void);
char *
grub_util_make_temporary_dir (void);
void
grub_util_unlink_recursive (const char *name);
grub_uint32_t
grub_util_get_mtime (const char *name);

#endif /* ! GRUB_BIOSDISK_MACHINE_UTIL_HEADER */
