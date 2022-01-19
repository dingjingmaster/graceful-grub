#ifndef GRUB_PROCFS_H
#define GRUB_PROCFS_H

#include "core/grub-list.h"
#include "core/grub-types.h"

struct grub_procfs_entry
{
  struct grub_procfs_entry *next;
  struct grub_procfs_entry **prev;

  const char *name;
  char * (*get_contents) (grub_size_t *sz);
};

extern struct grub_procfs_entry *grub_procfs_entries;

static inline void
grub_procfs_register (const char *name __attribute__ ((unused)),
		      struct grub_procfs_entry *entry)
{
  grub_list_push (GRUB_AS_LIST_P (&grub_procfs_entries),
		  GRUB_AS_LIST (entry));
}

static inline void
grub_procfs_unregister (struct grub_procfs_entry *entry)
{
  grub_list_remove (GRUB_AS_LIST (entry));
}


#endif
