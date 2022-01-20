#include "../config.h"

#include "../core/util/misc.h"
#include "../core/grub-i18n.h"
#include "../core/grub-term.h"
#include "../core/grub-font.h"
#include "../core/grub-gfxmenu_view.h"
#include "../core/grub-color.h"
#include "../core/util/install.h"
#include "../core/grub-command.h"
#include "../core/grub-env.h"

#define _GNU_SOURCE	1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "../core/gnulib/progname.h"

void grub_file_init (void);
void grub_host_init (void);
void grub_hostfs_init (void);

int
main (int argc, char *argv[])
{
  char **argv2;
  int i;
  int had_file = 0, had_separator = 0;
  grub_command_t cmd;
  grub_err_t err;

  grub_util_host_init (&argc, &argv);

  argv2 = xcalloc (argc, sizeof (argv2[0]));

  if (argc == 2 && strcmp (argv[1], "--version") == 0)
    {
      printf ("%s (%s) %s\n", program_name, PACKAGE_NAME, PACKAGE_VERSION);
    }

  for (i = 1; i < argc; i++)
    {
      if (argv[i][0] == '-' && argv[i][1] == '-'
	  && argv[i][2] == '\0' && !had_separator)
	{
	  had_separator = 1;
	  argv2[i - 1] = xstrdup (argv[i]);
	  continue;
	}
      if (argv[i][0] == '-' && !had_separator)
	{
	  argv2[i - 1] = xstrdup (argv[i]);
	  continue;
	}
      if (had_file)
	grub_util_error ("one argument expected");
      argv2[i - 1] = grub_canonicalize_file_name (argv[i]);
      if (!argv2[i - 1])
	{
	  grub_util_error (_("cannot open `%s': %s"), argv[i],
			   strerror (errno));
	}
      had_file = 1;
    }
  argv2[i - 1] = NULL;

  /* Initialize all modules. */
  grub_init_all ();
  grub_file_init ();
  grub_hostfs_init ();
  grub_host_init ();

  grub_env_set ("root", "host");

  cmd = grub_command_find ("file");
  if (! cmd)
    grub_util_error (_("can't find command `%s'"), "file");

  err = (cmd->func) (cmd, argc - 1, argv2);
  if (err && err != GRUB_ERR_TEST_FAILURE)
    grub_print_error ();
  return err;
}
