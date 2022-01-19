#ifndef GRUB_BIOSDISK_MACHINE_UTIL_H
#define GRUB_BIOSDISK_MACHINE_UTIL_H

#include <sys/types.h>

#include "../../core/grub-disk.h"
#include "../../core/grub-partition.h"
#include "../../core/emu/hostfile.h"

grub_util_fd_t
grub_util_fd_open_device (const grub_disk_t disk, grub_disk_addr_t sector, int flags,
			  grub_disk_addr_t *max);

void grub_util_biosdisk_init (const char *dev_map);
void grub_util_biosdisk_fini (void);
char *grub_util_biosdisk_get_grub_dev (const char *os_dev);
const char *grub_util_biosdisk_get_osdev (grub_disk_t disk);
int grub_util_biosdisk_is_present (const char *name);
int grub_util_biosdisk_is_floppy (grub_disk_t disk);
const char *
grub_util_biosdisk_get_compatibility_hint (grub_disk_t disk);
grub_err_t grub_util_biosdisk_flush (struct grub_disk *disk);
grub_err_t
grub_cryptodisk_cheat_mount (const char *sourcedev, const char *cheat);
const char *
grub_util_cryptodisk_get_uuid (grub_disk_t disk);
char *
grub_util_get_ldm (grub_disk_t disk, grub_disk_addr_t start);
int
grub_util_is_ldm (grub_disk_t disk);
#ifdef GRUB_UTIL
grub_err_t
grub_util_ldm_embed (struct grub_disk *disk, unsigned int *nsectors,
		     unsigned int max_nsectors,
		     grub_embed_type_t embed_type,
		     grub_disk_addr_t **sectors);
#endif
const char *
grub_hostdisk_os_dev_to_grub_drive (const char *os_dev, int add);


char *
grub_util_get_os_disk (const char *os_dev);

int
grub_util_get_dm_node_linear_info (dev_t dev,
				   int *maj, int *min,
				   grub_disk_addr_t *st);


/* Supplied by hostdisk_*.c.  */
grub_int64_t
grub_util_get_fd_size_os (grub_util_fd_t fd, const char *name, unsigned *log_secsize);
/* REturns partition offset in 512B blocks.  */
grub_disk_addr_t
grub_hostdisk_find_partition_start_os (const char *dev);
void
grub_hostdisk_flush_initial_buffer (const char *os_dev);

#ifdef __GNU__
int
grub_util_hurd_get_disk_info (const char *dev, grub_uint32_t *secsize, grub_disk_addr_t *offset,
			      grub_disk_addr_t *size, char **parent);
#endif

struct grub_util_hostdisk_data
{
  char *dev;
  int access_mode;
  grub_util_fd_t fd;
  int is_disk;
  int device_map;
};

void grub_host_init (void);
void grub_host_fini (void);
void grub_hostfs_init (void);
void grub_hostfs_fini (void);

#endif /* ! GRUB_BIOSDISK_MACHINE_UTIL_HEADER */
