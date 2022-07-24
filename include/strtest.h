#ifndef STRTEST_INCLUDED
#define STRTEST_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include "xstring.h"

#define RED "\033[0;31m"
#define GREEN "\033[1m\033[32m"
#define CYAN "\033[0;36m"
#define CLEAR "\033[0m"

void run_test_xmem();
void run_test_xstr();

void run_test_xmemcpy();
void run_test_xmemccpy();
void run_test_xmemchr();
void run_test_xmemrchr();
void run_test_xmemcmp();
void run_test_xmemmove();
void run_test_xmemset();

void run_test_xstpcpy();
void run_test_xstpncpy();
void run_test_xstrcat();
void run_test_xstrchr();
void run_test_xstrcmp();
void run_test_xstrcpy();
void run_test_xstrcspn();
void run_test_xstrdup();
void run_test_xstrlen();
void run_test_xstrncat();
void run_test_xstrncmp();
void run_test_xstrncpy();
void run_test_xstrndup();
void run_test_xstrnlen();
void run_test_xstrpbrk();
void run_test_xstrrchr();
void run_test_xstrspn();
void run_test_xstrtok();
void run_test_xstrtok_r();

// void run_test_xstrcoll();
// void run_test_xstrerror();
// void run_test_xstrerror_r();
// void run_test_xstrsignal();
// void run_test_xstrstr();
// void run_test_xstrxfrm();

#endif
