#ifndef GRUB_READER_H
#define GRUB_READER_H

#include "core/grub-err.h"

typedef grub_err_t (*grub_reader_getline_t) (char **, int, void *);

void grub_rescue_run (void) __attribute__ ((noreturn));

#endif /* ! GRUB_READER_HEADER */
