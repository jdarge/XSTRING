#ifndef XSTRING_INCLUDED
#define XSTRING_INCLUDED

#include <malloc.h>
#include "xstddef.h"

void   *xmemccpy(void *restrict dest, const void *restrict src, int c, size_t n);
void   *xmemchr(const void *dest, int i, size_t n);
void   *xmemrchr(const void *dest, int i, size_t n);
int     xmemcmp(const void *dest, const void * src, size_t n);
void   *xmemcpy(void *restrict dest, const void *restrict src, size_t n);
void   *xmemmove(void *dest, const void *src, size_t n);
void   *xmemset(void *dest, int i, size_t n);

char   *xstpcpy(char *restrict dest, const char *restrict src);
char   *xstpncpy(char *restrict dest, const char *restrict src, size_t n);
char   *xstrcat(char *restrict dest, const char *restrict src);
char   *xstrchr(const char *str, int c);
int     xstrcmp(const char *str1, const char *str2);
char   *xstrcpy(char *restrict dest, const char *restrict src);
size_t  xstrcspn(const char *str, const char *reject);
char   *xstrdup(const char *str);
size_t  xstrlen(const char *str);
char   *xstrncat(char *restrict dest, const char *restrict src, size_t n);
int     xstrncmp(const char *str1, const char *str2, size_t n);
char   *xstrncpy(char *restrict dest, const char *restrict src, size_t n);
char   *xstrndup(const char *str, size_t n);
size_t  xstrnlen(const char *str, size_t maxlen);
char   *xstrpbrk(const char *str, const char *accept);
char   *xstrrchr(const char *str, int c);
size_t  xstrspn(const char *str, const char *accept);
char   *xstrtok(char *restrict str, const char *restrict delim);
char   *xstrtok_r(char *restrict str, const char *restrict delim, char **restrict saveptr);

// TODO
//char   *xstrerror(int errnum);
//int     xstrerror_r(int errnum, char *buf, size_t buflen);
//char   *xstrsignal(int sig);
//char   *xstrstr(const char *haystack, const char *needle);v
//size_t  xstrxfrm(char *restrict dest, const char *restrict src, size_t n);

// TO.. LEARN...?
//int     xstrcoll(const char *dest, const char *src);
//int     xstrcoll_l(const char *dest, const char *src, locale_t loc);
//char   *xstrerror_l(int i, locale_t loc);
//size_t  xstrxfrm_l(char *restrict dest, const char *restrict src, size_t n, locale_t loc);

#endif
