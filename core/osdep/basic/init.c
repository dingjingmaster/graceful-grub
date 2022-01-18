#include "config.h"
#include "config-util.h"

#include "core/util/misc.h"
#include "core/grub-i18n.h"

#include "core/gnulib/progname.h"

void
grub_util_host_init (int *argc __attribute__ ((unused)),
		     char ***argv)
{
  set_program_name ((*argv)[0]);

#if (defined (GRUB_UTIL) && defined(ENABLE_NLS) && ENABLE_NLS)
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);
#endif /* (defined(ENABLE_NLS) && ENABLE_NLS) */
}
