//preexisiting functions --ft_putchar_fd
#include "libft.h"
#include "ft_print.h"

static const char hex[16] = "0123456789ABCDEF";

static const type_table handle_map[] = {
	{'c', handle_char},
	{'s', handle_str},
	{'p', handle_ptr},
	{'d', handle_int},
	{'i', handle_int},
	{'u', handle_unsigned},
	{'x', handle_hex},
	{'X', handle_hex},
	{'%', handle_char}
};

int get_index (char c)
{
	int index;

	index = 0;
	while (index < 8)
	{
		if (c == handle_map[index].symbol)
			return index;
		index ++;
	}
	return (-1);
}

int	handle_char(va_list *args, char symbol)
{
	char c;
	if (symbol == '%')
		ft_putchar_fd('%', 1);
	else
	{
		c = va_arg(*args, int);
		ft_putchar_fd(c, 1);
	}
	return 1;
}

int handle_str(va_list *args, char symbol)
{
	char *c;
	if (!symbol)
		return 0;
	c = va_arg(*args, char *);
	ft_putstr_fd(c, 1);
	return ft_strlen(c);
}

void print_ptr(uintptr_t ptr, int *count)
{
	char c;
	if (ptr >= 16)
		print_ptr(ptr/16, count);
	c = hex[ptr % 16];
	write (1, &c, 1);
	(*count) ++;
}

int handle_ptr(va_list *args, char symbol)
{
	int count;
	uintptr_t ptr;

	count = 0;
	ptr = (uintptr_t)(va_arg(*args, void*));
	write (1, "0x", 2);
	count ++;
	if (!ptr)
	{
		write(1, "0", 1);
		return (count ++);
	}
	print_ptr(ptr, &count);
	return (count);
}

int handle_int (va_list *args, char symbol)
{
	int		num;
	char	*str;
	int		length;
	
	num = va_arg(*args, int);
	str = ft_itoa(num);
	if (!str)
		return(0);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return(length);
}

int handle_unsigned (va_list *args, char symbol)
{
	unsigned int num;
	char *str;
	int length;

	num = va_arg(*args, unsigned int);
	str = ft_utoa(num);
	if (!str)
		return(0);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free (str);
	return (length);
}

char *hex_string(unsigned int hex_input)
{
	char *str;
	unsigned int ctr;
	int length;

	if (hex_input == 0)
		return ft_strdup("0");
	ctr = hex_input;
	length = 0;
	while (ctr > 0)
	{
		length ++;
		ctr = ctr/16;
	}
	str = malloc(length + 1);
	if (!str)
		return(NULL);
	str[length] = '\0';
	ctr = hex_input;
	while (length > 0)
	{
		str[length-1] = hex[hex_input%16];
		hex_input = hex_input/16;
		length --;
	}
	return (str);
}

int handle_hex (va_list *args, char symbol)
{
	int				count;
	unsigned int 	hex_input;
	char *			str;
	int				length;
	int				i;

	hex_input = va_arg(*args, unsigned int);
	str = hex_string(hex_input);
	if (!str)
		return (0);
	length = ft_strlen(str);
	i = 0;
	if (symbol == 'x')
	{
		while (i < length)
		{
			str[i] = ft_tolower(str[i]);
			i ++;
		}
	}
	ft_putstr_fd(str, 1);
	free(str);
	return(length);
}