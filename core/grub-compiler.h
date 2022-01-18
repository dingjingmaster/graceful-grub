#ifndef GRUBCOMPILER_H
#define GRUBCOMPILER_H

/* GCC version checking borrowed from glibc. */
#if defined(__GNUC__) && defined(__GNUC_MINOR__)
#  define GNUC_PREREQ(maj,min) \
((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
#  define GNUC_PREREQ(maj,min) 0
#endif

/* Does this compiler support compile-time error attributes? */
#if GNUC_PREREQ(4,3)
#  define ATTRIBUTE_ERROR(msg) \
    __attribute__ ((__error__ (msg)))
#else
#  define ATTRIBUTE_ERROR(msg) __attribute__ ((noreturn))
#endif

#if GNUC_PREREQ(4,4)
#  define GNU_PRINTF gnu_printf
#else
#  define GNU_PRINTF printf
#endif

#if GNUC_PREREQ(3,4)
#  define WARN_UNUSED_RESULT __attribute__ ((warn_unused_result))
#else
#  define WARN_UNUSED_RESULT
#endif

#if defined(__clang__) && defined(__clang_major__) && defined(__clang_minor__)
#  define CLANG_PREREQ(maj,min) \
    ((__clang_major__ > (maj)) || \
        (__clang_major__ == (maj) && __clang_minor__ >= (min)))
#else
#  define CLANG_PREREQ(maj,min) 0
#endif

#endif // GRUBCOMPILER_H
