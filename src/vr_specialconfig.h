#ifndef _VR_SPECIALCONFIG_H_
#define _VR_SPECIALCONFIG_H_

#if (__i386 || __amd64 || __powerpc__) && __GNUC__
#define GNUC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if defined(__clang__)
#define HAVE_ATOMIC
#endif
#if (defined(__GLIBC__) && defined(__GLIBC_PREREQ))
#if (GNUC_VERSION >= 40100 && __GLIBC_PREREQ(2, 6))
#define HAVE_ATOMIC
#endif
#endif
#endif


#if defined(__sun)
#if defined(__GNUC__)
#include <math.h>
#undef isnan
#define isnan(x) \
     __extension__({ __typeof (x) __x_a = (x); \
     __builtin_expect(__x_a != __x_a, 0); })

#undef isfinite
#define isfinite(x) \
     __extension__ ({ __typeof (x) __x_f = (x); \
     __builtin_expect(!isnan(__x_f - __x_f), 1); })

#undef isinf
#define isinf(x) \
     __extension__ ({ __typeof (x) __x_i = (x); \
     __builtin_expect(!isnan(__x_i) && !isfinite(__x_i), 0); })

#define u_int uint
#define u_int32_t uint32_t
#endif /* __GNUC__ */
#endif /* __sun */

#endif
