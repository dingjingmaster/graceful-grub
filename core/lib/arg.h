#ifndef GRUB_ARG_HEADER
#define GRUB_ARG_HEADER

#include "../grub-symbol.h"
#include "../grub-err.h"
#include "../grub-types.h"

enum grub_arg_type
  {
    ARG_TYPE_NONE,
    ARG_TYPE_STRING,
    ARG_TYPE_INT,
    ARG_TYPE_DEVICE,
    ARG_TYPE_FILE,
    ARG_TYPE_DIR,
    ARG_TYPE_PATHNAME
  };

typedef enum grub_arg_type grub_arg_type_t;

/* Flags for the option field op grub_arg_option.  */
#define GRUB_ARG_OPTION_OPTIONAL	(1 << 1)
/* Flags for an option that can appear multiple times.  */
#define GRUB_ARG_OPTION_REPEATABLE      (1 << 2)

enum grub_key_type
  {
    GRUB_KEY_ARG = -1,
    GRUB_KEY_END = -2
  };
typedef enum grub_key_type grub_arg_key_type_t;

struct grub_arg_option
{
  const char *longarg;
  int shortarg;
  int flags;
  const char *doc;
  const char *arg;
  grub_arg_type_t type;
};

struct grub_arg_list
{
  int set;
  union {
    char *arg;
    char **args;
  };
};

struct grub_extcmd;

int grub_arg_parse (struct grub_extcmd *cmd, int argc, char **argv,
		    struct grub_arg_list *usr, char ***args, int *argnum);

void EXPORT_FUNC(grub_arg_show_help) (struct grub_extcmd *cmd);
struct grub_arg_list* grub_arg_list_alloc (struct grub_extcmd *cmd,
					   int argc, char *argv[]);

#endif /* ! GRUB_ARG_HEADER */
