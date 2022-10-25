#ifndef STRTEST_INCLUDED
#define STRTEST_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include "xstring.h"

#define RED "\033[0;31m"
#define GREEN "\033[1m\033[32m"
#define CYAN "\033[0;36m"
#define CLEAR "\033[0m"

void run_test_xmem(void);
void run_test_xstr(void);

void run_test_xmemcpy(void);
void run_test_xmemccpy(void);
void run_test_xmemchr(void);
void run_test_xmemrchr(void);
void run_test_xmemcmp(void);
void run_test_xmemmove(void);
void run_test_xmemset(void);

void run_test_xstpcpy(void);
void run_test_xstpncpy(void);
void run_test_xstrcat(void);
void run_test_xstrchr(void);
void run_test_xstrcmp(void);
void run_test_xstrcpy(void);
void run_test_xstrcspn(void);
void run_test_xstrdup(void);
void run_test_xstrlen(void);
void run_test_xstrncat(void);
void run_test_xstrncmp(void);
void run_test_xstrncpy(void);
void run_test_xstrndup(void);
void run_test_xstrnlen(void);
void run_test_xstrpbrk(void);
void run_test_xstrrchr(void);
void run_test_xstrspn(void);
void run_test_xstrtok(void);
void run_test_xstrtok_r(void);

// void run_test_xstrcoll(void);
// void run_test_xstrerror(void);
// void run_test_xstrerror_r(void);
// void run_test_xstrsignal(void);
// void run_test_xstrstr(void);
// void run_test_xstrxfrm(void);

#endif
