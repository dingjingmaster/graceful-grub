#include "config-util.h"

#include "../grub-types.h"
#include "../grub-err.h"
#include "../grub-mm.h"
#include <stdlib.h>
#include <string.h>
#include "../grub-i18n.h"

void *
grub_calloc (grub_size_t nmemb, grub_size_t size)
{
  void *ret;
  ret = calloc (nmemb, size);
  if (!ret)
    grub_error (GRUB_ERR_OUT_OF_MEMORY, N_("out of memory"));
  return ret;
}

void *
grub_malloc (grub_size_t size)
{
  void *ret;
  ret = malloc (size);
  if (!ret)
    grub_error (GRUB_ERR_OUT_OF_MEMORY, N_("out of memory"));
  return ret;
}

void *
grub_zalloc (grub_size_t size)
{
  void *ret;

  ret = grub_malloc (size);
  if (!ret)
    return NULL;
  memset (ret, 0, size);
  return ret;
}

void
grub_free (void *ptr)
{
  if (ptr)
    free (ptr);
}

void *
grub_realloc (void *ptr, grub_size_t size)
{
  void *ret;
  ret = realloc (ptr, size);
  if (!ret)
    grub_error (GRUB_ERR_OUT_OF_MEMORY, N_("out of memory"));
  return ret;
}
