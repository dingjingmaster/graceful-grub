#ifndef GRUB_LIBZFS_UTIL_H
#define GRUB_LIBZFS_UTIL_H

#include "config.h"

#ifdef HAVE_LIBZFS_H
#include <libzfs.h>
#else /* ! HAVE_LIBZFS_H */

#include "core/util/libnvpair.h"

typedef void libzfs_handle_t;
typedef void zpool_handle_t;

extern libzfs_handle_t *libzfs_init (void);
extern void libzfs_fini (libzfs_handle_t *);

extern zpool_handle_t *zpool_open (libzfs_handle_t *, const char *);
extern void zpool_close (zpool_handle_t *);

extern int zpool_get_physpath (zpool_handle_t *, const char *);

extern nvlist_t *zpool_get_config (zpool_handle_t *, nvlist_t **);

#endif /* ! HAVE_LIBZFS_H */

libzfs_handle_t *grub_get_libzfs_handle (void);

#endif
