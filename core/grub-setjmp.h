#ifndef GRUB_SETJMP_H
#define GRUB_SETJMP_H

#if defined(GRUB_UTIL)
#include <setjmp.h>
typedef jmp_buf grub_jmp_buf;
#define grub_setjmp setjmp
#define grub_longjmp longjmp
#else

#include "grub-misc.h"

#if GNUC_PREREQ(4,0)
#define RETURNS_TWICE __attribute__ ((returns_twice))
#else
#define RETURNS_TWICE
#endif

/* This must define grub_jmp_buf, and declare grub_setjmp and
   grub_longjmp.  */
# include "cpu/setjmp.h"
#endif

#endif /* ! GRUB_SETJMP_HEADER */
