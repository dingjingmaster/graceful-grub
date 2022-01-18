#include "config.h"

#include "core/grub-types.h"
#include "core/grub-crypto.h"
#include "core/grub-auth.h"
#include "core/emu/misc.h"
#include "core/util/misc.h"
#include "core/grub-i18n.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
grub_get_random (void *out, grub_size_t len)
{
  FILE *f;
  size_t rd;

  f = grub_util_fopen ("/dev/urandom", "rb");
  if (!f)
    return 1;
  rd = fread (out, 1, len, f);
  fclose (f);

  if (rd != len)
    return 1;
  return 0;
}
