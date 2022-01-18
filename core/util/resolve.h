#ifndef GRUB_UTIL_RESOLVE_H
#define GRUB_UTIL_RESOLVE_H

struct grub_util_path_list
{
  const char *name;
  struct grub_util_path_list *next;
};

/* Resolve the dependencies of the modules MODULES using the information
   in the file DEP_LIST_FILE. The directory PREFIX is used to find files.  */
struct grub_util_path_list *
grub_util_resolve_dependencies (const char *prefix,
				const char *dep_list_file,
				char *modules[]);
void grub_util_free_path_list (struct grub_util_path_list *path_list);

#endif /* ! GRUB_UTIL_RESOLVE_HEADER */
