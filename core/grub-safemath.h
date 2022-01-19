#ifndef GRUB_SAFEMATH_H
#define GRUB_SAFEMATH_H

#include "grub-compiler.h"

/* These appear in gcc 5.1 and clang 3.8. */
#if GNUC_PREREQ(5, 1) || CLANG_PREREQ(3, 8)

#define grub_add(a, b, res)	__builtin_add_overflow(a, b, res)
#define grub_sub(a, b, res)	__builtin_sub_overflow(a, b, res)
#define grub_mul(a, b, res)	__builtin_mul_overflow(a, b, res)

#else
#error gcc 5.1 or newer or clang 3.8 or newer is required
#endif

#endif /* GRUB_SAFEMATH_H */
