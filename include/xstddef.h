#ifndef XSTDDEF_INCLUDED
#define XSTDDEF_INCLUDED

#undef NULL
#undef ptrdiff_t
#undef size_t
#undef wchar_t
#undef offsetof

#define NULL 0

typedef signed long int ptrdiff_t;
typedef unsigned long int size_t;
typedef int wchar_t;

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *) 0) -> MEMBER)

#endif
