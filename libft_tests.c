#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

// ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Helper function for string comparison
void assert_str(const char *test_name, const char *output, const char *expected)
{
    if (strcmp(output, expected) == 0)
    {
        printf("%s: %sTest passed%s\n", test_name, GREEN, RESET);
    }
    else
    {
        printf("%s: %sFAIL%s, got '%s', expected '%s'\n", test_name, RED, RESET, output, expected);
    }
}

void assert_int(const char *test_name, int output, int expected)
{
    if (output == expected)
    {
        printf("%s: %sTest passed%s\n", test_name, GREEN, RESET);
    }
    else
    {
        printf("%s: %sFAIL%s, got %d, expected %d\n", test_name, RED, RESET, output, expected);
    }
}

void assert_size_t(const char *test_name, size_t output, size_t expected)
{
    if (output == expected)
    {
        printf("%s: %sTest passed%s\n", test_name, GREEN, RESET);
    }
    else
    {
        printf("%s: %sFAIL%s, got %zu, expected %zu\n", test_name, RED, RESET, output, expected);
    }
}

// -------------------- Tests --------------------

void test_isalpha()
{
    assert_int("isalpha('a')", ft_isalpha('a'), 1);
    assert_int("isalpha('Z')", ft_isalpha('Z'), 1);
    assert_int("isalpha('1')", ft_isalpha('1'), 0);
    assert_int("isalpha('@')", ft_isalpha('@'), 0);
}

void test_isdigit()
{
    assert_int("isdigit('0')", ft_isdigit('0'), 1);
    assert_int("isdigit('9')", ft_isdigit('9'), 1);
    assert_int("isdigit('a')", ft_isdigit('a'), 0);
}

void test_isalnum()
{
    assert_int("isalnum('a')", ft_isalnum('a'), 1);
    assert_int("isalnum('9')", ft_isalnum('9'), 1);
    assert_int("isalnum('@')", ft_isalnum('@'), 0);
}

void test_isascii()
{
    assert_int("isascii(0)", ft_isascii(0), 1);
    assert_int("isascii(127)", ft_isascii(127), 1);
    assert_int("isascii(128)", ft_isascii(128), 0);
}

void test_isprint()
{
    assert_int("isprint(' ')", ft_isprint(' '), 1);
    assert_int("isprint('A')", ft_isprint('A'), 1);
    assert_int("isprint('\\n')", ft_isprint('\n'), 0);
}

void test_strlen()
{
    assert_size_t("strlen('Hello')", ft_strlen("Hello"), 5);
    assert_size_t("strlen('')", ft_strlen(""), 0);
    assert_size_t("strlen('Long string')", ft_strlen("Long string"), 11);
}

void test_memset()
{
    char buf[6] = "Hello";
    ft_memset(buf, 'A', 3);
    buf[5] = '\0';
    assert_str("memset test", buf, "AAAlo");
}

void test_bzero()
{
    char buf[6] = "Hello";
    ft_bzero(buf, 3);
    if (buf[0] == 0 && buf[1] == 0 && buf[2] == 0)
    {
        printf("bzero test: %sTest passed%s\n", GREEN, RESET);
    }
    else
    {
        printf("bzero test: %sFAIL%s\n", RED, RESET);
    }
}

void test_memcpy()
{
    char src[] = "Hello";
    char dest[6];
    ft_memcpy(dest, src, 5);
    dest[5] = '\0';
    assert_str("memcpy test", dest, "Hello");
}

void test_memmove()
{
    char buf[10] = "abcdef";
    ft_memmove(buf + 2, buf, 4); // overlapping
    buf[6] = '\0';
    assert_str("memmove test", buf, "ababcdf");
}

void test_strlcpy()
{
    char dest[6];
    size_t ret = ft_strlcpy(dest, "HelloWorld", sizeof(dest));
    assert_str("strlcpy content", dest, "Hello");
    assert_size_t("strlcpy return", ret, 10);
}

void test_strlcat()
{
    char dest[10] = "Hi";
    size_t ret = ft_strlcat(dest, "There", sizeof(dest));
    assert_str("strlcat content", dest, "HiThere");
    assert_size_t("strlcat return", ret, 7);
}

// -------------------- Main --------------------

int main()
{
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    return 0;
}
