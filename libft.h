#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *c);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlcat(char *dest, const char *src, size_t size);

// list of commands
/*
 * isalpha - checks for an alphabetic character
 • isdigit - checks for a digit
 • isalnum - check if it is alphabetical or digit
 • isascii - checks whether c is a 7-bit unsigned char value that fits into the ASCII character set
 // values return non-zero if true, returns zro if false
 • isprint - checks if it is a printable chracter
 • strlen - calculate the len of string pointed to by string, exclues the terminating byte
 • memset - fill first n bytes of memory area pointed to by s with constant byte c
 • bzero - erases the data in the first n bytes of the mrmory pointed to by s by writing \0 to the area
 • memcpy - copies n bytes from src to dest. the memory areas must not overlap. memmove should be used instead if the areas overlap. -- the function itself does not check for overlap. it does not pad with '\0', and it does not check if n > src, if it is, it copies rubbish in the memory
 • memmove - copies n bytes from src to dest. however src and dest may overlap, behaves AS THOUGH it copies from src to a temp buffer, then copies into dst. however using a temp buffer is memory inefficient.
 • strlcpy - copies up to size - 1 characters from src to dst, and nul terminates the result. length of string they tried to create - ie. src.
 • strlcat - appends src to end of dst. appends at most size - dst - 1 (ie size includes length of dst), nul terminating the result. however if dst > n, the string returned would not be nul terminating, and the output would be size. Else, output would be dst + src

 • toupper
 • tolower
 • strchr
 • strrchr
 • strncmp
 • memchr
 • memcmp
 • strnstr
 • atoi
 */

#endif