#ifndef	GRUB_I18N_H
#define	GRUB_I18N_H

#include "config.h"
#include "grub-symbol.h"

/* NLS can be disabled through the configure --disable-nls option.  */
#if (defined(ENABLE_NLS) && ENABLE_NLS) || !defined (GRUB_UTIL)

extern const char *(*EXPORT_VAR(grub_gettext)) (const char *s) __attribute__ ((format_arg (1)));

# ifdef GRUB_UTIL

#  include <locale.h>
#  include <libintl.h>

# endif /* GRUB_UTIL */

#else /* ! (defined(ENABLE_NLS) && ENABLE_NLS) */

/* Disabled NLS.
   The casts to 'const char *' serve the purpose of producing warnings
   for invalid uses of the value returned from these functions.
   On pre-ANSI systems without 'const', the config.h file is supposed to
   contain "#define const".  */
static inline const char * __attribute__ ((always_inline,format_arg (1)))
gettext (const char *str)
{
  return str;
}

#endif /* (defined(ENABLE_NLS) && ENABLE_NLS) */

#ifdef GRUB_UTIL
static inline const char * __attribute__ ((always_inline,format_arg (1)))
_ (const char *str)
{
  return gettext(str);
}
#else
static inline const char * __attribute__ ((always_inline,format_arg (1)))
_ (const char *str)
{
  return grub_gettext(str);
}
#endif /* GRUB_UTIL */

#define N_(str) str

#endif /* GRUB_I18N_H */
