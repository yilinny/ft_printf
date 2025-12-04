/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:19:12 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/12/04 14:41:04 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

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


static void print_params(va_list *args, int *printed, char specified)
{
	int i;
	int count;

	i = get_index(specified);
	if (i == -1)
		return; //check printf behavior for this
	count = handle_map[i].func(args, specified);
	(*printed) += count;
	return;
}

int ft_printf(const char *str, ...)
{
	int		printed;
	char	*ptr;
	char	specified; //specified should be string for dealing with bonus 
	va_list	args;

	va_start(args, str);
	printed = 0;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr ++;
			specified = *ptr;
			print_params(&args, &printed, specified); //advance va arg within funcion for correct type.
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			printed ++;
		}
		ptr ++;
	}
	va_end(args);
	return (printed);
}
