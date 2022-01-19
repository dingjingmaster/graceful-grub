#ifndef GRUB_EXFAT_H
#define GRUB_EXFAT_H

#include "grub-types.h"

struct grub_exfat_bpb
{
  grub_uint8_t jmp_boot[3];
  grub_uint8_t oem_name[8];
  grub_uint8_t mbz[53];
  grub_uint64_t num_hidden_sectors;
  grub_uint64_t num_total_sectors;
  grub_uint32_t num_reserved_sectors;
  grub_uint32_t sectors_per_fat;
  grub_uint32_t cluster_offset;
  grub_uint32_t cluster_count;
  grub_uint32_t root_cluster;
  grub_uint32_t num_serial;
  grub_uint16_t fs_revision;
  grub_uint16_t volume_flags;
  grub_uint8_t bytes_per_sector_shift;
  grub_uint8_t sectors_per_cluster_shift;
  grub_uint8_t num_fats;
  grub_uint8_t num_ph_drive;
  grub_uint8_t reserved[8];
} GRUB_PACKED;

#ifdef GRUB_UTIL
#include "grub-disk.h"

grub_disk_addr_t
grub_exfat_get_cluster_sector (grub_disk_t disk, grub_uint64_t *sec_per_lcn);
#endif

#endif
