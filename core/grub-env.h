#ifndef GRUB_ENV_H
#define GRUB_ENV_H

#include "core/grub-symbol.h"
#include "core/grub-err.h"
#include "core/grub-types.h"
#include "core/grub-menu.h"

struct grub_env_var;

typedef const char *(*grub_env_read_hook_t) (struct grub_env_var *var,
					     const char *val);
typedef char *(*grub_env_write_hook_t) (struct grub_env_var *var,
					const char *val);

struct grub_env_var
{
  char *name;
  char *value;
  grub_env_read_hook_t read_hook;
  grub_env_write_hook_t write_hook;
  struct grub_env_var *next;
  struct grub_env_var **prevp;
  struct grub_env_var *sorted_next;
  int global;
};

grub_err_t EXPORT_FUNC(grub_env_set) (const char *name, const char *val);
const char *EXPORT_FUNC(grub_env_get) (const char *name);
void EXPORT_FUNC(grub_env_unset) (const char *name);
struct grub_env_var *EXPORT_FUNC(grub_env_update_get_sorted) (void);

#define FOR_SORTED_ENV(var) for (var = grub_env_update_get_sorted (); var; var = var->sorted_next)

grub_err_t EXPORT_FUNC(grub_register_variable_hook) (const char *name,
						     grub_env_read_hook_t read_hook,
						     grub_env_write_hook_t write_hook);

grub_err_t grub_env_context_open (void);
grub_err_t grub_env_context_close (void);
grub_err_t EXPORT_FUNC(grub_env_export) (const char *name);

void grub_env_unset_menu (void);
grub_menu_t grub_env_get_menu (void);
void grub_env_set_menu (grub_menu_t nmenu);

grub_err_t
grub_env_extractor_open (int source);

grub_err_t
grub_env_extractor_close (int source);


#endif /* ! GRUB_ENV_HEADER */
