#include "xstring.h"

/*
DESCRIPTION
	The memccpy() function copies no more than n bytes from memory area src to memory area dest, 
		stopping when the character c is found.
	If the memory areas overlap, the results are undefined.

RETURN VALUE
	The memccpy() function returns a pointer to the next character in dest after c, 
		or NULL if c was not found in the first n characters of src.
*/
void *xmemccpy(void *restrict dest, const void *restrict src, int c, size_t n) {

	unsigned char *d = (unsigned char *) dest;
	unsigned char *s = (unsigned char *) src;

	while(n-- && (*d++ = *s++) != c);

	if(n) return d + 1;
	return 0;
}

/*
DESCRIPTION
	The memchr() function scans the initial n bytes of the memory area pointed to by src for 
		the first instance of c. Both c and the bytes of the memory area pointed to by src 
		are interpreted as unsigned char.

RETURN VALUE
	The memchr() function return a pointer to the matching byte or NULL if the character does 
		not occur in the given memory area.
*/
void *xmemchr(const void *src, int c, size_t n) {

	unsigned char* s = (unsigned char*) src;

	while(n--) {
		if((unsigned char) c == *s++) {
			return (void*) (s-1);
		}
	}

	return NULL;
}

void *xmemrchr(const void *src, int c, size_t n) {

	unsigned char* s = (unsigned char*) src;

	while(n--) {
		if((unsigned char) c == s[n]) {
			return (void*) (s+n);
		}
	}

	return NULL;
}

/*
DESCRIPTION
	The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the 
		memory areas mem_p1 and mem_p2.

RETURN VALUE
	The  memcmp() function  returns an integer less than, equal to, or greater than zero if 
		the first n bytes of mem_p1 is found, respectively, to be less than, to match, or be greater 
		than the first n bytes of mem_p2.

	For a nonzero return value, the sign is determined by the sign of the difference between 
		the first pair of bytes (interpreted as unsigned char) that differ in mem_p1 and mem_p2.

	If n is zero, the return value is zero.
*/
int xmemcmp(const void *mem_p1, const void * mem_p2, size_t n) {

	int ret = 0;

	unsigned char *t_p1 = (unsigned char *) mem_p1;
	unsigned char *t_p2 = (unsigned char *) mem_p2;

	for(; n > 0; n--) {
		if((ret = *t_p1 - *t_p2)) break;
	}

	return ret;
}

/*
DESCRIPTION
	The memcpy() function  copies n bytes from memory area src to memory area dest. 
		The memory areas must not overlap.  Use memmove(3) if the memory areas do overlap.

RETURN VALUE
	The memcpy()function returns a pointer to dest.
*/
void *xmemcpy(void *restrict dest, const void *restrict src, size_t n) {

	unsigned char *d = (unsigned char *) dest;
	unsigned char *s = (unsigned char *) src;

	for(size_t i = 0; i < n; i++) {
		*d++ = *s++;
	}

	return dest; 
}

/*
DESCRIPTION
	The memmove() function  copies n bytes from memory area src to memory area dest.  
		The memory areas may overlap: copying takes place as though the bytes in src are 
		first copied into a temporary array that does not overlap src or dest, and the 
		bytes are then copied from the temporary array to dest.

RETURN VALUE
	The memmove() function returns a pointer to dest.
*/
void *xmemmove(void *dest, const void *src, size_t n) {

	char* d = (char*) dest;
	char* s = (char*) src;

	if(dest <= src) {
		while(n--) *d++ = *s++;
	} else {
		d += n; s += n;
		while(n--) *--d = *--s;
	}

	return dest;
}

/*
DESCRIPTION
	The memset() function fills the first n bytes of the memory area pointed to by s with 
		the constant byte c.

RETURN VALUE
	The memset() function returns a pointer to the memory area s.
*/
void *xmemset(void *mem_p, int i, size_t n) {

	char* p = (char*) mem_p;

	while(n--) *p++ = i;

	return mem_p;
}

/*
DESCRIPTION
	The stpcpy() function copies the string pointed to by src (including the terminating null byte ('\0'))
	to the array pointed to by dest. The strings may not overlap, and the destination string dest must 
	be large enough to receive the copy.

RETURN VALUE
	stpcpy() returns a pointer to the end of the string dest (that is, the address of the terminating 
	null byte) rather than the beginning.
*/
char *xstpcpy(char *restrict dest, const char *restrict src) {

	while((*dest++ = *src++));

	return dest - 1;
}

/*
DESCRIPTION
	The stpncpy() function copies at most n characters from the string pointed to by src, including 
	the	terminating null byte ('\0'), to the array pointed to by dest. Exactly n characters are 
	written at dest. If the length strlen(src) is smaller than n, the remaining characters in the 
	array pointed to by dest are filled with null bytes ('\0'), If the length strlen(src) is greater 
	than or equal to n, the string pointed to by dest will not be null-terminated.

	The strings may not overlap.

	The programmer must ensure that there is room for at least n characters at dest.

RETURN VALUE
	stpncpy() returns a pointer to the terminating null byte in dest, or, if dest is not 
	null-terminated, dest+n.
*/
char *xstpncpy(char *restrict dest, const char *restrict src, size_t n) {

	while(n-- && (*dest++ = *src++));
	xmemset(dest, 0, 1);// not sure about this 

	return dest;
}

/*
DESCRIPTION
	The  strcat()  function appends the src string to the dest string, overwriting the terminating 
		null byte ('\0') at the end of dest, and then adds a terminating null byte. The strings 
		may not overlap, and the dest string must have enough space for the result. If dest is 
		not large enough,  program behavior is unpredictable; buffer overruns are a favorite avenue 
		for attacking secure programs.

	Rhe resulting string in dest is always null-terminated.

RETURN VALUE
	The strcat() functions return a pointer to the resulting string dest.
*/
char *xstrcat(char *restrict dest, const char *restrict src) {

	char* s = dest;

	while(*dest) dest++;
	while((*dest++ = *src++) != '\0');

	return s;
}

/*
DESCRIPTION
	The strchr() function returns a pointer to the first occurrence of the character c in the 
		string s.

	Here "character" means "byte"; this function does not work with wide or multibyte characters.

RETURN VALUE
	The strchr() function return a pointer to the matched character or NULL if the character is 
	not found. The terminating null byte is considered part of the string, so that if c is 
	specified as '\0', these functions return a pointer to the terminator.
*/
char *xstrchr(const char *str, int c) {

	while (*str != (char) c) {
		if(*str++ == '\0') return NULL;
	}

	return (char*) str;
}

/*
DESCRIPTION
The strcmp() function  compares the two strings s1 and s2. The locale is not taken into account. 
	The comparison is done using unsigned characters.

strcmp() returns an integer indicating the result of the comparison, as follows:
	• 0, if the s1 and s2 are equal;
	• a negative value if s1 is less than s2;
	• a positive value if s1 is greater than s2.

RETURN VALUE
	The strcmp() functions return an integer less than, equal to, or greater than zero if s1 is 
	found to be less than, to match, or be greater than s2.
*/
int xstrcmp(const char *str1, const char *str2) {

	unsigned char str1__;
	unsigned char str2__;

	do {

		str1__ = *str1++;
		str2__ = *str2++;

		if(str1__ - str2__) break;

	} while (str1__);

	return (str1__ - str2__);
}

/*
DESCRIPTION
	The strcpy() function copies the string pointed to by src, including the terminating null 
	byte ('\0'), to the buffer pointed to by dest. The strings may not overlap, and the 
	destination string dest must be large enough to receive the copy. Beware of buffer overruns!

RETURN VALUE
	The strcpy() function return a pointer to the destination string dest.
*/
char *xstrcpy(char *restrict dest, const char *restrict src) {

	char* s = dest;

	while((*dest++ = *src++) != '\0');

	return s;
}

/*
DESCRIPTION
	The strcspn() function calculates the length of the initial segment of str which consists 
	entirely of bytes not in reject.

RETURN VALUE
	The strcspn() function returns the number of bytes in the initial segment of str which are 
	not in the string reject.
*/
size_t xstrcspn(const char *str, const char *reject) {

	size_t count = 0;

	for(const char *s = str; *s != '\0'; ++s, ++count) {
		for(const char *r = reject; *r != '\0'; ++r) {
				if(*s == *r) return count;
		}
	}

	return count;
}

/*
DESCRIPTION
	The strdup() function returns a pointer to a new string which is a duplicate of the string 
	s. Memory for the new string is obtained with malloc(3), and can be freed with free(3).

RETURN VALUE
	On success, the strdup() function returns a pointer to the duplicated string. It returns 
	NULL if insufficient memory was available, with errno set to indicate the error.
*/
char *xstrdup(const char *str) {

	char* str_new = (char*) malloc(xstrlen(str) + 1);

	if(!str_new) return NULL;

	return xstrcpy(str_new, str);
}

/*
DESCRIPTION
	The strlen() function calculates the length of the string pointed to by s, excluding the 
	terminating null byte ('\0').

RETURN VALUE
	The strlen() function returns the number of bytes in the string pointed to by s.
*/
size_t xstrlen(const char *str) {

	const char *s = str;

	while(*s) s++;

	return s-str;
}

/*
DESCRIPTION
	The  strncat() function appends the src string to the dest string, overwriting the 
	terminating null byte ('\0') at the end of dest, and then adds a terminating null byte. 
	The strings may not overlap, and the dest string must have enough space for the result. 
	If dest is not large enough,  program behavior is unpredictable; buffer overruns are a 
	favorite avenue for attacking secure programs.
		*  it will use at most n bytes from src; and
		*  src does not need to be null-terminated if it contains n or more bytes.

RETURN VALUE
	The strcat() function returns a pointer to the resulting string dest.
*/
char *xstrncat(char *restrict dest, const char *restrict src, size_t n) {

	char *s = dest;

	if(!n) return s;

	while(*dest) dest++;
	while((*dest++ = *src++)) {
		if(--n == 0) {
			*dest = '\0';
			break;
		}
	}

	return s;
}

/*
DESCRIPTION
	The strncmp() function compares the first n bytes of the two strings str1 and str2. The 
	locale is not taken into account. The comparison is done using unsigned characters.

	strncmp() returns an integer indicating the result of the comparison, as follows:
		• 0, if the str1 and str2 are equal;
		• a negative value if s1 is less than str2;
		• a positive value if s1 is greater than str2.
*/
int xstrncmp(const char *str1, const char *str2, size_t n) {

	unsigned char str1__;
	unsigned char str2__;

	while(n--) {

		str1__ = *str1++;
		str2__ = *str2++;

		if(str1__ - str2__) {
			return (str1__ < str2__ ? -1 : 1);
		}

		if(!str1__) break;
	}

	return 0;
}

/*
DESCRIPTION
	The strncpy() function copies at most n bytes of the string pointed to by src, including 
	the terminating null byte ('\0'), to the buffer pointed to by dest. The strings may not 
	overlap, and the destination string dest must be large enough to receive the copy. Beware 
	of buffer overruns!
		Warning: If there is no null byte among the first n bytes of src, the string 
		placed in dest will not be null-terminated.

	If the length of src is less than n, strncpy() writes additional null bytes to dest to 
	ensure that a total of n bytes are written.

RETURN VALUE
	The strncpy() function returns a pointer to the destination string dest.
*/
char *xstrncpy(char *restrict dest, const char *restrict src, size_t n) {

	char* s = dest;

	while(n--) {
		if ((*dest++ = *src++) == '\0') break;
	}

	return s;
}

/*
DESCRIPTION
	The strndup() function returns a pointer to a new string which is a duplicate of the 
	string str. Memory for the new string is obtained with malloc(3), and can be freed with 
	free(3).

	The strndup() copies at most n bytes. If str is longer than n, only n bytes are copied, 
	and a terminating null byte ('\0') is added.

RETURN VALUE
	On success, the strndup() function returns a pointer to the duplicated string. It returns 
	NULL if insufficient memory was available, with errno set to indicate the error.
*/
char *xstrndup(const char *str, size_t n) {

	size_t s_length = xstrnlen(str, n);
	char* s = malloc(s_length + 1);

	if(!s) return NULL;

	xmemcpy(s, str, s_length);
	s[s_length] = '\0';

	return s;
}

/*
DESCRIPTION
	The strnlen() function returns the number of bytes in the string pointed to by s, excluding 
	the terminating null byte ('\0'), but at most maxlen. In doing this, strnlen() looks only 
	at the first maxlen characters in the string pointed to by str and never beyond s[maxlen-1].

RETURN VALUE
	The strnlen() function returns strlen(s), if that is less than maxlen, or maxlen if there 
	is no null terminating ('\0') among the first maxlen characters pointed to by s.
*/
size_t xstrnlen(const char *str, size_t maxlen) {

	const char* p = xmemchr(str, 0, maxlen);

	if(p) {
		return p - str;
	}

	return maxlen;
}

/*
DESCRIPTION
	The strpbrk() function locates the first occurrence in the string str of any of the bytes in 
	the string accept.

RETURN VALUE
	The strpbrk() function returns a pointer to the byte in str that matches one of the bytes in 
	accept, or NULL if no such byte is found.
*/
char *xstrpbrk(const char *str, const char *accept) {

	str += xstrcspn(str, accept);
	
	if(*str) {
		return (char*) str;
	}

	return NULL;
}

/*
DESCRIPTION
	The strrchr() function returns a pointer to the last occurrence of the character c in 
	the string str.

	Here "character" means "byte"; these functions do not work with wide or multibyte characters.

RETURN VALUE
	The strrchr() function returns a pointer to the matched character or NULL if the character is 
	not found. The terminating null byte is considered part of the string, so that if c is 
	specified as '\0', these functions return a pointer to the terminator.
*/
char *xstrrchr(const char *str, int c) {

	return xmemrchr(str, c, xstrlen(str) + 1);
}

/*
DESCRIPTION
	The strspn() function calculates the length (in bytes) of the initial segment of str which 
	consists entirely of bytes in accept.

RETURN VALUE
	The strspn() function returns the number of bytes in the initial segment of str which consist 
	only of bytes from accept.
*/
size_t xstrspn(const char *str, const char *accept) {

	size_t count = 0;

	const char *s;
	const char *a;

	for(s = str; *s != '\0'; ++s, ++count) {
		for(a = accept; *a != '\0'; ++a) {
			if(*s == *a) break;
		}

		if(*a == '\0') return count;
	}

	return count;
}

/*
DESCRIPTION
	The strtok() function  breaks a string into a sequence of zero or more nonempty tokens. On the 
	first call to strtok(), the string to be parsed should be specified in str. In each subsequent 
	call that should parse the same string, str must be NULL.

	The delim argument specifies a set of bytes that delimit the tokens in the parsed string. The 
	caller may specify different strings in delim in successive calls that parse the same string.

	Each  call  to strtok() returns a pointer to a null-terminated string containing the next token. 
	This string does not include the delimiting byte. If no more tokens are found, strtok() returns 
	NULL.

	A sequence of calls to strtok() that operate on the same string maintains a pointer that 
	determines the point from which to start searching for the next token. The first call to strtok() 
	sets this pointer to point to the first byte of the string. The start of the next token is 
	determined by scanning forward for the next nondelimiter byte in str. If such a byte is found, 
	it is taken as the start of the next token. If no such byte is found, then there are no more tokens,
	and strtok() returns NULL. (A string that is empty or that contains only delimiters will thus cause
	 strtok() to return NULL on the first call.)

	The end of each token is found by scanning forward until either the next delimiter byte is found or 
	until the terminating null byte ('\0') is encountered. If a delimiter byte is found, it is 
	overwritten with a null byte to terminate the current token, and strtok() saves a pointer to the
	following byte; that pointer will be used as the starting point when searching for the next token. 
	In this case, strtok() returns a pointer to the start of the found token.

	From the above description, it follows that a sequence of two or more contiguous delimiter bytes 
	in the parsed string is considered to be a single delimiter, and that delimiter bytes at the start 
	or end of the string are ignored. Put another way: the tokens returned by strtok() are always
	nonempty strings. Thus, for example, given the string "aaa;;bbb,", successive calls to strtok() 
	that specify the delimiter string ";," would return the strings "aaa" and "bbb", and then a 
	null pointer.

RETURN VALUE
	The strtok() functions return a pointer to the next token, or NULL if there are no more tokens.
*/
char *xstrtok(char *restrict str, const char *restrict delim) {

	static char* p;

	if(!str && !(str=p)) return NULL;

	str += xstrspn(str, delim);
	if(!*str) return NULL;

	p = str + xstrcspn(str, delim);
	if(*p) *p++ = '\0';
	else p = '\0';

	return str;
}

/*
DESCRIPTION
	SIMILAR TO strtok()

	The strtok() function  breaks a string into a sequence of zero or more nonempty tokens. On the 
	first call to strtok(), the string to be parsed should be specified in str. In each subsequent 
	call that should parse the same string, str must be NULL.

	The delim argument specifies a set of bytes that delimit the tokens in the parsed string. The 
	caller may specify different strings in delim in successive calls that parse the same string.

	Each  call  to strtok() returns a pointer to a null-terminated string containing the next token. 
	This string does not include the delimiting byte. If no more tokens are found, strtok() returns 
	NULL.

	A sequence of calls to strtok() that operate on the same string maintains a pointer that 
	determines the point from which to start searching for the next token. The first call to strtok() 
	sets this pointer to point to the first byte of the string. The start of the next token is 
	determined by scanning forward for the next nondelimiter byte in str. If such a byte is found, 
	it is taken as the start of the next token. If no such byte is found, then there are no more tokens,
	and strtok() returns NULL. (A string that is empty or that contains only delimiters will thus cause
	 strtok() to return NULL on the first call.)

	The end of each token is found by scanning forward until either the next delimiter byte is found or 
	until the terminating null byte ('\0') is encountered. If a delimiter byte is found, it is 
	overwritten with a null byte to terminate the current token, and strtok() saves a pointer to the
	following byte; that pointer will be used as the starting point when searching for the next token. 
	In this case, strtok() returns a pointer to the start of the found token.

	From the above description, it follows that a sequence of two or more contiguous delimiter bytes 
	in the parsed string is considered to be a single delimiter, and that delimiter bytes at the start 
	or end of the string are ignored. Put another way: the tokens returned by strtok() are always
	nonempty strings. Thus, for example, given the string "aaa;;bbb,", successive calls to strtok() 
	that specify the delimiter string ";," would return the strings "aaa" and "bbb", and then a 
	null pointer.

	The strtok_r() function is a reentrant version of strtok(). The saveptr argument is a pointer to 
	a char * variable that is used internally by strtok_r() in order to maintain context between 
	successive calls that parse the same string.

	On the first call to strtok_r(), str should point to the string to be parsed, and the value of 
	*saveptr is ignored. In subsequent calls, str should be NULL, and saveptr (and the buffer 
	that it points to) should be unchanged since the previous call.

	Different strings may be parsed concurrently using sequences of calls to strtok_r() that specify 
	different saveptr arguments.

RETURN VALUE
	The strtok() and strtok_r() functions return a pointer to the next token, or NULL if there are 
	no more tokens.
*/
char *xstrtok_r(char *restrict str, const char *restrict delim, char **restrict saveptr) {

	if(!str && !(str = *saveptr)) return NULL;

	str += xstrspn(str, delim);
	if(!*str) return NULL;

	*saveptr = str + xstrcspn(str, delim);
	if(**saveptr) *(*saveptr)++ = '\0';
	else *saveptr = '\0';

	return str;
}

/*
DESCRIPTION
	The strerror() function returns a pointer to a string that describes the error code passed 
	in the argument errnum, possibly using the LC_MESSAGES part of the current locale to select 
	the appropriate language. (For example, if errnum is EINVAL, the returned description will 
	be "Invalid  argument".) This string must not be modified by the application, but may be 
	modified by a subsequent call to strerror() or strerror_l(). No other library function, 
	including perror(3), will modify this string.

RETURN VALUE
	The strerror() function returns the appropriate error description string, or an "Unknown 
	error nnn" message if the error number is unknown.

	POSIX.1-2001 and POSIX.1-2008 require that a successful call to strerror() shall leave errno 
	unchanged, and note that, since no function return value is reserved to indicate an error, 
	an application that wishes to check for errors should initialize errno to zero before the call,
	and then check errno after the call.
*/
/*char *xstrerror(int errnum) {// TODO

	return NULL;
}*/

/*
DESCRIPTION
	The strerror_r() function is similar to strerror(), but is thread safe. This function is available 
	in two versions: an XSI-compliant version specified in POSIX.1-2001 (available since glibc 2.3.4, 
	but not POSIX-compliant until glibc 2.13), and a GNU-specific version (available since glibc 2.0). 
	The XSI-compliant version is provided with the feature test macros settings shown in the SYNOPSIS; 
	otherwise the GNU-specific version is provided. If no feature test macros are explicitly defined, 
	then (since glibc 2.4) _POSIX_C_SOURCE is defined by default with the value 200112L, so that the 
	XSI-compliant version of strerror_r() is provided by default.

	The XSI-compliant strerror_r() is preferred for portable applications. It returns the error string 
	in the user-supplied buffer buf of  length  buflen.

	The GNU-specific strerror_r() returns a pointer to a string containing the error message. This may 
	be either a pointer to a string that the function stores in buf, or a pointer to some (immutable) 
	static string (in which case buf is unused). If the function stores a string in buf, then at most 
	buflen bytes are stored (the string may be truncated if buflen is too small and errnum is unknown). 
	The string always includes a terminating null byte ('\0').

RETURN VALUE
	The GNU-specific strerror_r() functions return the appropriate error description string, or an 
	"Unknown error nnn" message if the error number is unknown.

	The  XSI-compliant strerror_r() function returns 0 on success. On error, a (positive) error 
	number is returned (since glibc 2.13), or -1 is returned and errno is set to indicate the 
	error (glibc versions before 2.13).
*/
/*int xstrerror_r(int errnum, char *buf, size_t buflen) {// TODO

	return 0xDEADBEEF;
}*/

/*
DESCRIPTION
	The strsignal() function returns a string describing the signal number passed in the argument 
	sig. The string can be used only until the next call to strsignal(). The string returned by 
	strsignal() is localized according to the LC_MESSAGES category in the current locale.

RETURN VALUE
	The strsignal() function returns the appropriate description string, or an unknown signal 
	message if the signal number is invalid.
*/
/*char *xstrsignal(int sig) {// TODO

	return NULL;
}*/

/*
DESCRIPTION
	The strstr() function finds the first occurrence of the substring needle in the string haystack. 
	The terminating null bytes ('\0') are not compared.

RETURN VALUE
	This function returns a pointer to the beginning of the located substring, or NULL if the substring 
	is not found.

	If needle is the empty string, the return value is always haystack itself.
*/
/*char *xstrstr(const char *haystack, const char *needle) {// TODO

	return NULL;
}*/

/*
DESCRIPTION
	The strxfrm() function transforms the src string into a form such that the result of strcmp(3) 
	on two strings that have been transformed with strxfrm() is the same as the result of strcoll(3)
	on the two strings before their transformation. The first n bytes of the transformed string  are
	placed in dest. The transformation is based on the program's current locale for category LC_COLLATE.

RETURN VALUE
	The strxfrm() function returns the number of bytes required to store the transformed string in dest 
	excluding the terminating null byte ('\0'). If the value returned is n or more, the contents of dest 
	are indeterminate.
*/
/*size_t xstrxfrm(char *restrict dest, const char *restrict src, size_t n) {// TODO

	return 0xDEADBEEF;
}*/
