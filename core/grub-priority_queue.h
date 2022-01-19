#ifndef GRUB_PRIORITY_QUEUE_H
#define GRUB_PRIORITY_QUEUE_H

#include "core/grub-misc.h"
#include "core/grub-err.h"

#ifdef __cplusplus
extern "C" {
#endif

struct grub_priority_queue;
typedef struct grub_priority_queue *grub_priority_queue_t;
typedef int (*grub_comparator_t) (const void *a, const void *b);

grub_priority_queue_t grub_priority_queue_new (grub_size_t elsize,
					       grub_comparator_t cmp);
void grub_priority_queue_destroy (grub_priority_queue_t pq);
void *grub_priority_queue_top (grub_priority_queue_t pq);
void grub_priority_queue_pop (grub_priority_queue_t pq);
grub_err_t grub_priority_queue_push (grub_priority_queue_t pq, const void *el);

#ifdef __cplusplus
}
#endif

#endif
