#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
	char symbol;
	int (*func)(va_list *, char);
} type_table;

int		get_index(char c);
char	*ft_utoa(unsigned int n);
int		handle_char(va_list *args, char symbol);
int		handle_str(va_list *args, char symbol);
int		handle_ptr(va_list *args, char symbol);
int		handle_int(va_list *args, char symbol);
int		handle_unsigned(va_list *args, char symbol);
int		handle_hex(va_list *args, char symbol);
int		ft_printf(const char *str, ...);