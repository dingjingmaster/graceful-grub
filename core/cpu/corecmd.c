#include "core/grub-mm.h"
#include "core/grub-dl.h"
#include "core/grub-err.h"
#include "core/grub-env.h"
#include "core/grub-misc.h"
#include "core/grub-term.h"
#include "core/grub-file.h"
#include "core/grub-device.h"
#include "core/grub-command.h"
#include "core/grub-i18n.h"

/* set ENVVAR=VALUE */
static grub_err_t
grub_core_cmd_set (struct grub_command *cmd __attribute__ ((unused)),
		   int argc, char *argv[])
{
  char *var;
  char *val;

  if (argc < 1)
    {
      struct grub_env_var *env;
      FOR_SORTED_ENV (env)
	grub_printf ("%s=%s\n", env->name, grub_env_get (env->name));
      return 0;
    }

  var = argv[0];
  val = grub_strchr (var, '=');
  if (! val)
    return grub_error (GRUB_ERR_BAD_ARGUMENT, "not an assignment");

  val[0] = 0;
  grub_env_set (var, val + 1);
  val[0] = '=';

  return 0;
}

static grub_err_t
grub_core_cmd_unset (struct grub_command *cmd __attribute__ ((unused)),
		     int argc, char *argv[])
{
  if (argc < 1)
    return grub_error (GRUB_ERR_BAD_ARGUMENT,
		       N_("one argument expected"));

  grub_env_unset (argv[0]);
  return 0;
}

/* insmod MODULE */
static grub_err_t
grub_core_cmd_insmod (struct grub_command *cmd __attribute__ ((unused)),
		      int argc, char *argv[])
{
  grub_dl_t mod;

  if (argc == 0)
    return grub_error (GRUB_ERR_BAD_ARGUMENT, N_("one argument expected"));

  if (argv[0][0] == '/' || argv[0][0] == '(' || argv[0][0] == '+')
    mod = grub_dl_load_file (argv[0]);
  else
    mod = grub_dl_load (argv[0]);

  if (mod)
    grub_dl_ref (mod);

  return 0;
}

static int
grub_mini_print_devices (const char *name, void *data __attribute__ ((unused)))
{
  grub_printf ("(%s) ", name);

  return 0;
}

static int
grub_mini_print_files (const char *filename,
		       const struct grub_dirhook_info *info,
		       void *data __attribute__ ((unused)))
{
  grub_printf ("%s%s ", filename, info->dir ? "/" : "");

  return 0;
}

/* ls [ARG] */
static grub_err_t
grub_core_cmd_ls (struct grub_command *cmd __attribute__ ((unused)),
		  int argc, char *argv[])
{
  if (argc < 1)
    {
      grub_device_iterate (grub_mini_print_devices, NULL);
      grub_xputs ("\n");
      grub_refresh ();
    }
  else
    {
      char *device_name;
      grub_device_t dev = 0;
      grub_fs_t fs;
      char *path;

      device_name = grub_file_get_device_name (argv[0]);
      if (grub_errno)
	goto fail;
      dev = grub_device_open (device_name);
      if (! dev)
	goto fail;

      fs = grub_fs_probe (dev);
      path = grub_strchr (argv[0], ')');
      if (! path)
	path = argv[0];
      else
	path++;

      if (! *path && ! device_name)
	{
	  grub_error (GRUB_ERR_BAD_ARGUMENT, "invalid argument");
	  goto fail;
	}

      if (! *path)
	{
	  if (grub_errno == GRUB_ERR_UNKNOWN_FS)
	    grub_errno = GRUB_ERR_NONE;

	  grub_printf ("(%s): Filesystem is %s.\n",
		       device_name, fs ? fs->name : "unknown");
	}
      else if (fs)
	{
	  (fs->fs_dir) (dev, path, grub_mini_print_files, NULL);
	  grub_xputs ("\n");
	  grub_refresh ();
	}

    fail:
      if (dev)
	grub_device_close (dev);

      grub_free (device_name);
    }

  return grub_errno;
}

void
grub_register_core_commands (void)
{
  grub_command_t cmd;
  cmd = grub_register_command ("set", grub_core_cmd_set,
			       N_("[ENVVAR=VALUE]"),
			       N_("Set an environment variable."));
  if (cmd)
    cmd->flags |= GRUB_COMMAND_FLAG_EXTRACTOR;
  grub_register_command ("unset", grub_core_cmd_unset,
			 N_("ENVVAR"),
			 N_("Remove an environment variable."));
  grub_register_command ("ls", grub_core_cmd_ls,
			 N_("[ARG]"), N_("List devices or files."));
  grub_register_command ("insmod", grub_core_cmd_insmod,
			 N_("MODULE"), N_("Insert a module."));
}
