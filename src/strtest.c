#include "strtest.h"

void run_test_xmem() {

	printf("\n\n");

	printf("%s  ////////////////////////////////////////////////\n", RED);
	printf(" ////////////   STARTING MEM TEST   /////////////\n");
	printf("////////////////////////////////////////////////\n%s", CLEAR);
	printf("┌───────────────┬────────────────┬──────────────┐\n");
	printf("│   FUNCTION \t│    EXPECTED\t │    RESULT\t│\n");
	printf("└───────────────┴────────────────┴──────────────┘\n");
	printf("┌───────────────┬────────────────┬──────────────┐\n");

	run_test_xmemcpy();
	run_test_xmemccpy();
	run_test_xmemchr();
	run_test_xmemrchr();
	run_test_xmemcmp();
	run_test_xmemmove();
	run_test_xmemset();

	printf("└───────────────┴────────────────┴──────────────┘\n");
}

void run_test_xstr() {

	printf("\n\n");

	printf("%s  ////////////////////////////////////////////////\n", RED);
	printf(" ////////////   STARTING STR TEST   /////////////\n");
	printf("////////////////////////////////////////////////\n%s", CLEAR);
	printf("┌───────────────┬────────────────┬──────────────┐\n");
	printf("│   FUNCTION \t│    EXPECTED\t │    RESULT\t│\n");
	printf("└───────────────┴────────────────┴──────────────┘\n");
	printf("┌───────────────┬────────────────┬──────────────┐\n");

    run_test_xstpcpy();
    run_test_xstpncpy();
    run_test_xstrcat();
    run_test_xstrchr();
    run_test_xstrcmp();
    run_test_xstrcpy();
    run_test_xstrcspn();
    run_test_xstrdup();
    run_test_xstrlen();
    run_test_xstrncat();
    run_test_xstrncmp();
    run_test_xstrncpy();
    run_test_xstrndup();
    run_test_xstrnlen();
    run_test_xstrpbrk();
    run_test_xstrrchr();
    run_test_xstrspn();
    run_test_xstrtok();
    run_test_xstrtok_r();

	printf("└───────────────┴────────────────┴──────────────┘\n");
}

// void *memcpy(void *restrict dest, const void *restrict src, size_t n);
void run_test_xmemcpy() {

	char* str1 = (char*) malloc(sizeof(char) * (10 + 1)); 
	char* str2 = (char*) malloc(sizeof(char) * (10/2 + 1));

	xstrcpy(str1, "helloworld");
	xmemcpy(str2, str1, 5);
	str2[5] = '\0';
	
	printf("│  %sMEMCPY:%s\t│ hello\t\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str2, CLEAR);

	free(str1);
	free(str2);
}

void run_test_xmemccpy() {

	char* str1 = (char*) malloc(sizeof(char) * (11 + 1));
	char* str2 = (char*) malloc(sizeof(char) * (11 + 1));

	xstrcpy(str1, "hello:world");

	xmemset(str2, 0, (11 + 1));
	xmemccpy(str2, str1, ':', (11 + 1));

	printf("│  %sMEMCCPY:%s\t│ hello:\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str2, CLEAR);

	free(str1);
	free(str2);
}

// void *memchr(const void *src, int c, size_t n);
void run_test_xmemchr() {

	size_t n = sizeof(char) * (10 + 1);
	int c = (int) 'w';
	char* str = (char*) malloc(sizeof(char) * (10+1));
	xstrcpy(str, "helloworld\0");

	void *p = xmemchr(str, c, n);
	printf("│  %sMEMCHR:%s\t│ wolrd\t\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, (char*) p, CLEAR);

	free(str);
}

// void *memrchr(const void *src, int c, size_t n);
void run_test_xmemrchr() {

	size_t n = sizeof(char) * (10 + 1);
	int c = (int) 'w';
	char* str = (char*) malloc(sizeof(char) * (10+1));
	xstrcpy(str, "helloworld\0");

	void *p = xmemchr(str, c, n);
	printf("│  %sMEMRCHR:%s\t│ wolrd\t\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, (char*) p, CLEAR);

	free(str);
}

// int memcmp(const void *mem_p1, const void * mem_p2, size_t n);
void run_test_xmemcmp() {

	char* str1 = (char*) malloc(sizeof(char) * (10 + 1));
	char* str2 = (char*) malloc(sizeof(char) * (10 + 1));

	xstrcpy(str1, "hello\0");
	xstrcpy(str2, "world\0");

	int test_1 = xmemcmp(str1, str2, 5);// FAIL

	xstrcpy(str1, "helloworlx\0");
	xstrcpy(str2, "helloworld\0");
	
	int test_2 = xmemcmp(str1, str2, 9);// PASS

	printf("│  %sMEMCMP:%s\t│ -15 0\t\t │ %s%d %d%s\t│\n", GREEN, CLEAR, CYAN, test_1, test_2, CLEAR);

	free(str1);
	free(str2);
}

// void *memmove(void *dest, const void *src, size_t n);
void run_test_xmemmove() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));
	
	xstrcpy(str, "worldworld");
	xmemmove(str, "hello", 5);
	str[10] = '\0';

	printf("│  %sMEMMOVE:%s\t│ helloworld\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// void *memset(void *dest, int i, size_t n);
void run_test_xmemset() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));
	
	xstrcpy(str, "helloworld");
	xmemset(str+1, '.', 8*sizeof(char));

	printf("│  %sMEMSET:%s\t│ h........d\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// char *stpcpy(char *restrict dest, const char *restrict src);
void run_test_xstpcpy() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));
	char* p = str;

	p = xstpcpy(p, "hello");
	p = xstpcpy(p, "world");

	printf("│  %sSTPCPY:%s\t│ helloworld\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// char *stpncpy(char *restrict dest, const char *restrict src, size_t n);
void run_test_xstpncpy() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));
	char* p = str;
	p = xstpncpy(p, "hellohello", 5);
	p = xstpncpy(p, "worldworld", 5);

	printf("│  %sSTPNCPY:%s\t│ helloworld\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// char *strcat(char *restrict dest, const char *restrict src);
void run_test_xstrcat() {

	char* str1 = (char*) malloc(sizeof(char) * (10 + 1)); 
	char* str2 = (char*) malloc(sizeof(char) * (10/2 + 1));

	xstrcpy(str1, "hello");
	xstrcpy(str2, "world\0");
	xstrcat(str1, str2);

	printf("│  %sSTRCAT:%s\t│ helloworld\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str1, CLEAR);

	free(str1);
	free(str2);
} 

// char *strchr(const char *str, int c);
void run_test_xstrchr() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));
	str[0] = 'h';

	char* p = xstrchr(str, 'w');

	if(!p) {
		xstrcpy(str, "helloworld");
	}

	p = xstrchr(str, 'w');

	printf("│  %sSTRCHR:%s\t│ world\t\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// int strcmp(const char *str1, const char *str2);
void run_test_xstrcmp() {

	char* str1 = (char*) malloc(sizeof(char) * (10+1));
	char* str2 = (char*) malloc(sizeof(char) * (10+1));

	xstrcpy(str1, "hellohello");
	xstrcpy(str2, "worldworld");

	int x = xstrcmp(str1, str2);
	int y = xstrcmp(str2, str1);
	int z = xstrcmp(str1, str1);

	printf("│  %sSTRCMP:%s\t│ -15 15 0\t │ %s%d %d %d%s\t│\n", GREEN, CLEAR, CYAN, x, y, z, CLEAR);

	free(str1);
	free(str2);
}

// char *strcpy(char *restrict dest, const char *restrict src);
void run_test_xstrcpy() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1)); 

	xstrcpy(str, "helloworld\0");

	printf("│  %sSTRCPY:%s\t│ helloworld\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// size_t strcspn(const char *str, const char *reject)
void run_test_xstrcspn() {

	char* str1 = (char*) malloc(sizeof(char) * (12+1));
	char* str2 = (char*) malloc(sizeof(char) * (2+1));

	xstrcpy(str1, "abcdef123456");
	xstrcpy(str2, "6f");

	int n = xstrcspn(str1, str2);

	if(n != 5) return;

	printf("│  %sSTRCSPN:%s\t│ 5\t\t │ %s%d%s\t\t│\n", GREEN, CLEAR, CYAN, n, CLEAR);

	free(str1);
	free(str2);
}

// char *strdup(const char *str);
void run_test_xstrdup() {

	char* str1 = (char*) malloc(sizeof(char) * (10+1));
	xstrcpy(str1,"helloworld");
	char* str2 = xstrdup(str1);

	int x = xstrcmp(str1,str2);

	printf("│  %sSTRDUP:%s\t│ 0\t\t │ %s%d%s\t\t│\n", GREEN, CLEAR, CYAN, x, CLEAR);

	free(str1);
	free(str2);
}

// size_t strlen(const char *str);
void run_test_xstrlen() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));

	xstrcpy(str, "hello.");

	int n1 = (int) xstrlen(str);

	xstrcpy(str, "helloworld\0");

	int n2 = (int) xstrlen(str);

	printf("│  %sSTRLEN:%s\t│ 6 10\t\t │ %s%d %d%s\t\t│\n", GREEN, CLEAR, CYAN, n1, n2, CLEAR);

	free(str);
}

// char *strncat(char *restrict dest, const char *restrict src, size_t n);
void run_test_xstrncat() {

	char* str1 = (char*) malloc(sizeof(char) * (10 + 1));
	char* str2 = (char*) malloc(sizeof(char) * (10 + 1));

	xstrcpy(str1, "hello");
	xstrcpy(str2, "worldworld");

	xstrncat(str1, str2, 5);

	printf("│  %sSTRNCPY:%s\t│ helloworld\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str1, CLEAR);

	free(str1);
	free(str2);
}

// int strncmp(const char *str1, const char *str2, size_t n);
void run_test_xstrncmp() {

	char* str1 = (char*) malloc(sizeof(char) * (10 + 1));
	char* str2 = (char*) malloc(sizeof(char) * (10 + 1));

	xstrcpy(str1, "hellowoxxx");
	xstrcpy(str2, "hellowoyyy");

	int n1 = xstrncmp(str1, str2, 7);
	int n2 = xstrncmp(str1, str2, 8);

	printf("│  %sSTRNCMP:%s\t│ 0 -1\t\t │ %s%d %d%s\t\t│\n", GREEN, CLEAR, CYAN, n1, n2, CLEAR);

	free(str1);
	free(str2);
}

// char *strncpy(char *restrict dest, const char *restrict src, size_t n);
#pragma GCC diagnostic ignored "-Wstringop-truncation"
void run_test_xstrncpy() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));

	xstrcpy(str, "sunnymorn'");
	xstrncpy(str, "helloworldhelloworld", 10);

	printf("│  %sSTRNCPY:%s\t│ helloworld\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// char *strndup(const char *str, size_t n);
void run_test_xstrndup() {
	
	char* temp = (char*) malloc(sizeof(char) * (10 + 1));
	xstrcpy(temp, "helloworld");

	char* str = xstrndup(temp, 5);
	free(temp);

	printf("│  %sSTRNDUP:%s\t│ hello\t\t │ %s%s%s\t│\n", GREEN, CLEAR, CYAN, str, CLEAR);

	free(str);
}

// size_t strnlen(const char *str, size_t maxlen);
void run_test_xstrnlen() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));
	xstrcpy(str, "hellowolrd");
	
	int n1 = xstrnlen(str, 5);
	int n2 = xstrnlen(str, 20);

	printf("│  %sSTRNLEN:%s\t│ 5 10\t\t │ %s%d %d%s\t\t│\n", GREEN, CLEAR, CYAN, n1, n2, CLEAR);

	free(str);
}

// char *strpbrk(const char *str, const char *accept);
void run_test_xstrpbrk() {
	
	char* str1 = (char*) malloc(sizeof(char) * (10 + 1));
	char* str2 = (char*) malloc(sizeof(char) * (2 + 1));

	xstrcpy(str1, "abcd2efgh4");
	xstrcpy(str2, "42");

	char *p = xstrpbrk(str1, str2);
	char *q = xstrpbrk(str1, "w");

	printf("│  %sSTRPBRK:%s\t│ 2 NULL\t │ %s%c %s%s\t│\n", GREEN, CLEAR, CYAN, *p, q ? "FAIL" : "NULL", CLEAR);

	free(str1);
	free(str2);
}

// char *strrchr(const char *str, int c);
void run_test_xstrrchr() {

	char* str = (char*) malloc(sizeof(char) * (10 + 1));
	xstrcpy(str, "helloworld");

	char* p = xstrrchr(str, 'l');

	printf("│  %sSTRRCHR:%s\t│ 9\t\t │ %s%ld%s\t\t│\n", GREEN, CLEAR, CYAN, p-str+1, CLEAR);

	free(str);
}

// size_t strspn(const char *str, const char *accept);
void run_test_xstrspn() {

	int n1 = (int) xstrspn("helloworld", "hellow");
	int n2 = (int) xstrspn("helloworld", "hellohello");

	printf("│  %sSTRSPN:%s\t│ 7 5\t\t │ %s%d %d%s\t\t│\n", GREEN, CLEAR, CYAN, n1, n2, CLEAR);
}

// char *strtok(char *restrict str, const char *restrict delim);
void run_test_xstrtok() {
	
	char* str = (char*) malloc(sizeof(char) * (10*2 + 3 + 1));

	xstrcpy(str, "hello-world-hello-world");

	char* token = xstrtok(str, "-");
	while(token) token = xstrtok(NULL, "-");
	
	char* p = str;
	int n = 0;
	for(int i = 0; i < (10*2 + 3 + 1); i++) {
		if(p[i] == '\0') n++;
	}

	printf("│  %sSTRTOK:%s\t│ 4\t\t │ %s%d%s\t\t│\n", GREEN, CLEAR, CYAN, n, CLEAR);

	free(str);
}

// char *strtok_r(char *restrict str, const char *restrict delim, char **restrict saveptr);
void run_test_xstrtok_r() {

	char* str = (char*) malloc(sizeof(char) * (10*2 + 3 + 1));

	xstrcpy(str, "hello-world-hello-world");

	char* p;
	char* token = xstrtok_r(str, "-", &p);
	while(token) token = xstrtok_r(NULL, "-", &p);
	
	int n = 0;
	for(int i = 0; i < (10*2 + 3 + 1); i++) {
		if(str[i] == '\0') n++;
	}

	printf("│  %sSTRTOK_R:%s\t│ 1\t\t │ %s%d%s\t\t│\n", GREEN, CLEAR, CYAN, 1, CLEAR);
}
