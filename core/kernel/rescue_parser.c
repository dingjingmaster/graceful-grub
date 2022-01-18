#include "core/grub-types.h"
#include "core/grub-mm.h"
#include "core/grub-env.h"
#include "core/grub-parser.h"
#include "core/grub-misc.h"
#include "core/grub-command.h"
#include "core/grub-i18n.h"

grub_err_t
grub_rescue_parse_line (char *line,
			grub_reader_getline_t getline, void *getline_data)
{
  char *name;
  int n;
  grub_command_t cmd;
  char **args;

  if (grub_parser_split_cmdline (line, getline, getline_data, &n, &args)
      || n < 0)
    return grub_errno;

  if (n == 0)
    return GRUB_ERR_NONE;

  /* In case of an assignment set the environment accordingly
     instead of calling a function.  */
  if (n == 1)
    {
      char *val = grub_strchr (args[0], '=');

      if (val)
	{
	  val[0] = 0;
	  grub_env_set (args[0], val + 1);
	  val[0] = '=';
	  goto quit;
	}
    }

  /* Get the command name.  */
  name = args[0];

  /* If nothing is specified, restart.  */
  if (*name == '\0')
    goto quit;

  cmd = grub_command_find (name);
  if (cmd)
    {
      (cmd->func) (cmd, n - 1, &args[1]);
    }
  else
    {
      grub_printf_ (N_("Unknown command `%s'.\n"), name);
      if (grub_command_find ("help"))
	grub_printf ("Try `help' for usage\n");
    }

 quit:
  /* Arguments are returned in single memory chunk separated by zeroes */
  grub_free (args[0]);
  grub_free (args);

  return grub_errno;
}
