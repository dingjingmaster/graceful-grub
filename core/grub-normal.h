#ifndef GRUB_NORMAL_H
#define GRUB_NORMAL_H

#include "core/grub-term.h"
#include "core/grub-symbol.h"
#include "core/grub-err.h"
#include "core/grub-env.h"
#include "core/grub-menu.h"
#include "core/grub-command.h"
#include "core/grub-file.h"

/* The standard left and right margin for some messages.  */
#define STANDARD_MARGIN 6

/* The type of a completion item.  */
enum grub_completion_type
  {
    GRUB_COMPLETION_TYPE_COMMAND,
    GRUB_COMPLETION_TYPE_DEVICE,
    GRUB_COMPLETION_TYPE_PARTITION,
    GRUB_COMPLETION_TYPE_FILE,
    GRUB_COMPLETION_TYPE_ARGUMENT
  };
typedef enum grub_completion_type grub_completion_type_t;

extern struct grub_menu_viewer grub_normal_text_menu_viewer;
extern int grub_normal_exit_level;

/* Defined in `main.c'.  */
void grub_enter_normal_mode (const char *config);
void grub_normal_execute (const char *config, int nested, int batch);
struct grub_term_screen_geometry
{
  /* The number of entries shown at a time.  */
  int num_entries;
  int first_entry_y;
  int first_entry_x;
  int entry_width;
  int timeout_y;
  int timeout_lines;
  int border;
  int right_margin;
};

void grub_menu_init_page (int nested, int edit,
			  struct grub_term_screen_geometry *geo,
			  struct grub_term_output *term);
void grub_normal_init_page (struct grub_term_output *term, int y);
char *grub_file_getline (grub_file_t file);
void grub_cmdline_run (int nested, int force_auth);

/* Defined in `cmdline.c'.  */
char *grub_cmdline_get (const char *prompt);
grub_err_t grub_set_history (int newsize);

/* Defined in `completion.c'.  */
char *grub_normal_do_completion (char *buf, int *restore,
				 void (*hook) (const char *item, grub_completion_type_t type, int count));

/* Defined in `misc.c'.  */
grub_err_t grub_normal_print_device_info (const char *name);

/* Defined in `color.c'.  */
char *grub_env_write_color_normal (struct grub_env_var *var, const char *val);
char *grub_env_write_color_highlight (struct grub_env_var *var, const char *val);
int grub_parse_color_name_pair (grub_uint8_t *ret, const char *name);

/* Defined in `menu_text.c'.  */
void grub_wait_after_message (void);
void
grub_print_ucs4 (const grub_uint32_t * str,
		 const grub_uint32_t * last_position,
		 int margin_left, int margin_right,
		 struct grub_term_output *term);

void
grub_print_ucs4_menu (const grub_uint32_t * str,
		      const grub_uint32_t * last_position,
		      int margin_left, int margin_right,
		      struct grub_term_output *term,
		      int skip_lines, int max_lines, grub_uint32_t contchar,
		      struct grub_term_pos *pos);
int
grub_ucs4_count_lines (const grub_uint32_t * str,
		       const grub_uint32_t * last_position,
		       int margin_left, int margin_right,
		       struct grub_term_output *term);
grub_size_t grub_getstringwidth (grub_uint32_t * str,
				 const grub_uint32_t * last_position,
				 struct grub_term_output *term);
void grub_print_message_indented (const char *msg, int margin_left,
				  int margin_right,
				  struct grub_term_output *term);
void
grub_menu_text_register_instances (int entry, grub_menu_t menu, int nested);
grub_err_t
grub_show_menu (grub_menu_t menu, int nested, int autobooted);

/* Defined in `handler.c'.  */
void read_handler_list (void);
void free_handler_list (void);

/* Defined in `dyncmd.c'.  */
void read_command_list (const char *prefix);

/* Defined in `autofs.c'.  */
void read_fs_list (const char *prefix);

void grub_context_init (void);
void grub_context_fini (void);

void read_crypto_list (const char *prefix);

void read_terminal_list (const char *prefix);

void grub_set_more (int onoff);

void grub_normal_reset_more (void);

void grub_xputs_normal (const char *str);

extern int grub_extractor_level;

grub_err_t
grub_normal_add_menu_entry (int argc, const char **args, char **classes,
			    const char *id,
			    const char *users, const char *hotkey,
			    const char *prefix, const char *sourcecode,
			    int submenu);

grub_err_t
grub_normal_set_password (const char *user, const char *password);

void grub_normal_free_menu (grub_menu_t menu);

void grub_normal_auth_init (void);
void grub_normal_auth_fini (void);

void
grub_xnputs (const char *str, grub_size_t msg_len);

grub_command_t
grub_dyncmd_get_cmd (grub_command_t cmd);

void
grub_gettext_reread_prefix (const char *val);

enum grub_human_size_type
  {
    GRUB_HUMAN_SIZE_NORMAL,
    GRUB_HUMAN_SIZE_SHORT,
    GRUB_HUMAN_SIZE_SPEED,
  };

const char *
grub_get_human_size (grub_uint64_t size, enum grub_human_size_type type);

#endif /* ! GRUB_NORMAL_HEADER */
