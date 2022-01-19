#include "core/grub-types.h"
#include "core/grub-reader.h"
#include "core/grub-parser.h"
#include "core/grub-misc.h"
#include "core/grub-term.h"
#include "core/grub-mm.h"

#define GRUB_RESCUE_BUF_SIZE	256

static char linebuf[GRUB_RESCUE_BUF_SIZE];

/* Prompt to input a command and read the line.  */
static grub_err_t
grub_rescue_read_line (char **line, int cont,
		       void *data __attribute__ ((unused)))
{
  int c;
  int pos = 0;
  char str[4];

  grub_printf ((cont) ? "> " : "grub rescue> ");
  grub_memset (linebuf, 0, GRUB_RESCUE_BUF_SIZE);

  while ((c = grub_getkey ()) != '\n' && c != '\r')
    {
      if (grub_isprint (c))
	{
	  if (pos < GRUB_RESCUE_BUF_SIZE - 1)
	    {
	      str[0] = c;
	      str[1] = 0;
	      linebuf[pos++] = c;
	      grub_xputs (str);
	    }
	}
      else if (c == '\b')
	{
	  if (pos > 0)
	    {
	      str[0] = c;
	      str[1] = ' ';
	      str[2] = c;
	      str[3] = 0;
	      linebuf[--pos] = 0;
	      grub_xputs (str);
	    }
	}
      grub_refresh ();
    }

  grub_xputs ("\n");
  grub_refresh ();

  *line = grub_strdup (linebuf);

  return 0;
}

void __attribute__ ((noreturn))
grub_rescue_run (void)
{
  grub_printf ("Entering rescue mode...\n");

  while (1)
    {
      char *line;

      /* Print an error, if any.  */
      grub_print_error ();
      grub_errno = GRUB_ERR_NONE;

      grub_rescue_read_line (&line, 0, NULL);
      if (! line || line[0] == '\0')
	continue;

      grub_rescue_parse_line (line, grub_rescue_read_line, NULL);
      grub_free (line);
    }
}
