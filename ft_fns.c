/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:35:48 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/20 12:37:28 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*final;
	unsigned int	index;
	unsigned int	length;

	index = 0;
	if (!s)
		return (NULL);
	length = (unsigned int)ft_strlen(s);
	final = (char *)malloc(length + 1);
	if (final == NULL)
		return (NULL);
	while (index < length)
	{
		final[index] = f(index, s[index]);
		index ++;
	}
	final[length] = '\0';
	return (final);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	index;
	int	length;

	length = ft_strlen(s);
	index = 0;
	while (index < length)
	{
		f(index, s + index);
		index ++;
	}
}
