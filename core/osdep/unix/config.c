#include <config.h>
#include <config-util.h>

#include "core/emu/hostdisk.h"
#include "core/emu/exec.h"
#include "core/emu/config.h"
#include "core/util/install.h"
#include "core/util/misc.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

const char *
grub_util_get_config_filename (void)
{
  static char *value = NULL;
  if (!value)
    value = grub_util_path_concat (3, GRUB_SYSCONFDIR,
				   "default", "grub");
  return value;
}

const char *
grub_util_get_pkgdatadir (void)
{
  const char *ret = getenv ("pkgdatadir");
  if (ret)
    return ret;
  return GRUB_DATADIR "/" PACKAGE;
}

const char *
grub_util_get_pkglibdir (void)
{
  return GRUB_LIBDIR "/" PACKAGE;
}

const char *
grub_util_get_localedir (void)
{
  return LOCALEDIR;
}

void
grub_util_load_config (struct grub_util_config *cfg)
{
  pid_t pid;
  const char *argv[4];
  char *script, *ptr;
  const char *cfgfile, *iptr;
  FILE *f = NULL;
  int fd;
  const char *v;

  memset (cfg, 0, sizeof (*cfg));

  v = getenv ("GRUB_ENABLE_CRYPTODISK");
  if (v && v[0] == 'y' && v[1] == '\0')
    cfg->is_cryptodisk_enabled = 1;

  v = getenv ("GRUB_DISTRIBUTOR");
  if (v)
    cfg->grub_distributor = xstrdup (v);

  cfgfile = grub_util_get_config_filename ();
  if (!grub_util_is_regular (cfgfile))
    return;

  argv[0] = "sh";
  argv[1] = "-c";

  script = xcalloc (4, strlen (cfgfile) + 300);

  ptr = script;
  memcpy (ptr, ". '", 3);
  ptr += 3;
  for (iptr = cfgfile; *iptr; iptr++)
    {
      if (*iptr == '\\')
	{
	  memcpy (ptr, "'\\''", 4);
	  ptr += 4;
	  continue;
	}
      *ptr++ = *iptr;
    }

  strcpy (ptr, "'; printf \"GRUB_ENABLE_CRYPTODISK=%s\\nGRUB_DISTRIBUTOR=%s\\n\" "
	  "\"$GRUB_ENABLE_CRYPTODISK\" \"$GRUB_DISTRIBUTOR\"");

  argv[2] = script;
  argv[3] = '\0';

  pid = grub_util_exec_pipe (argv, &fd);
  if (pid)
    f = fdopen (fd, "r");
  if (f)
    {
      grub_util_parse_config (f, cfg, 1);
      fclose (f);
    }
  if (pid)
    {
      close (fd);
      waitpid (pid, NULL, 0);
    }
  if (f)
    return;

  f = grub_util_fopen (cfgfile, "r");
  if (f)
    {
      grub_util_parse_config (f, cfg, 0);
      fclose (f);
    }
  else
    grub_util_warn (_("cannot open configuration file `%s': %s"),
		    cfgfile, strerror (errno));
}
