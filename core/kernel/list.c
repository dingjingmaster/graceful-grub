#include "core/grub-list.h"
#include "core/grub-misc.h"
#include "core/grub-mm.h"

void *
grub_named_list_find (grub_named_list_t head, const char *name)
{
  grub_named_list_t item;

  FOR_LIST_ELEMENTS (item, head)
    if (grub_strcmp (item->name, name) == 0)
      return item;

  return NULL;
}

void
grub_list_push (grub_list_t *head, grub_list_t item)
{
  item->prev = head;
  if (*head)
    (*head)->prev = &item->next;
  item->next = *head;
  *head = item;
}

void
grub_list_remove (grub_list_t item)
{
  if (item->prev)
    *item->prev = item->next;
  if (item->next)
    item->next->prev = item->prev;
  item->next = 0;
  item->prev = 0;
}
