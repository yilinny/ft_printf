/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:46:39 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/12/04 15:48:37 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct table
{
	char	symbol;
	int		(*func)(va_list *, char);
}	t_type_table;

int		get_index(char c);
char	*ft_utoa(unsigned int n);
int		handle_char(va_list *args, char symbol);
int		handle_str(va_list *args, char symbol);
int		handle_ptr(va_list *args, char symbol);
int		handle_int(va_list *args, char symbol);
int		handle_unsigned(va_list *args, char symbol);
int		handle_hex(va_list *args, char symbol);
int		ft_printf(const char *str, ...);