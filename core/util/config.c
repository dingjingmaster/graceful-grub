#include "config.h"

#include <string.h>

#include "core/emu/config.h"
#include "misc.h"

void
grub_util_parse_config (FILE *f, struct grub_util_config *cfg, int simple)
{
  char *buffer = NULL;
  size_t sz = 0;
  while (getline (&buffer, &sz, f) >= 0)
    {
      const char *ptr;
      for (ptr = buffer; *ptr && grub_isspace (*ptr); ptr++);
      if (grub_strncmp (ptr, "GRUB_ENABLE_CRYPTODISK=",
			sizeof ("GRUB_ENABLE_CRYPTODISK=") - 1) == 0)
	{
	  ptr += sizeof ("GRUB_ENABLE_CRYPTODISK=") - 1;
	  if (*ptr == '"' || *ptr == '\'')
	    ptr++;
	  if (*ptr == 'y')
	    cfg->is_cryptodisk_enabled = 1;
	  continue;
	}
      if (grub_strncmp (ptr, "GRUB_DISTRIBUTOR=",
			sizeof ("GRUB_DISTRIBUTOR=") - 1) == 0)
	{
	  char *optr;
	  enum { NONE, SNGLQUOT, DBLQUOT } state;

	  ptr += sizeof ("GRUB_DISTRIBUTOR=") - 1;

	  if (simple)
	    {
	      char *ptr2;
	      free (cfg->grub_distributor);
	      cfg->grub_distributor = xstrdup (ptr);
	      for (ptr2 = cfg->grub_distributor
		     + grub_strlen (cfg->grub_distributor) - 1;
		   ptr2 >= cfg->grub_distributor
		     && (*ptr2 == '\r' || *ptr2 == '\n'); ptr2--);
	      ptr2[1] = '\0';
	      continue;
	    }
	  free (cfg->grub_distributor);
	  cfg->grub_distributor = xmalloc (strlen (ptr) + 1);
	  optr = cfg->grub_distributor;
	  state = NONE;

	  for (; *ptr; ptr++)
	    switch (*ptr)
	      {
	      case '\\':
		if (state == SNGLQUOT)
		  {
		    *optr++ = *ptr;
		    continue;
		  }
		if (ptr[1])
		  {
		    *optr++ = ptr[1];
		    ptr++;
		    continue;
		  }
		ptr++;
		break;
	      case '"':
		if (state == NONE)
		  {
		    state = DBLQUOT;
		    continue;
		  }
		if (state == DBLQUOT)
		  {
		    state = NONE;
		    continue;
		  }
		*optr++ = *ptr;
		continue;
	      case '\'':
		if (state == SNGLQUOT)
		  {
		    state = NONE;
		    continue;
		  }
		if (state == NONE)
		  {
		    state = SNGLQUOT;
		    continue;
		  }
		*optr++ = *ptr;
		continue;
	      default:
		*optr++ = *ptr;
		continue;
	      }
	  *optr = '\0';
	}
    }
}

