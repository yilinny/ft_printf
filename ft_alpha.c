/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:31:25 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/20 12:35:33 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	a;
	unsigned char	b;

	index = 0;
	while (index < n)
	{
		a = (unsigned char)s1[index];
		b = (unsigned char)s2[index];
		if (a != b)
			return (a - b);
		if (a == '\0')
			return (0);
		index ++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	char	*final;
	size_t	index;
	size_t	s_index;

	final = (char *)big;
	index = 0;
	if (small[0] == '\0')
		return (final);
	while (big[index] && index < len)
	{
		s_index = 0;
		while (big[index + s_index] == small[s_index] && index + s_index < len)
		{
			s_index ++;
			if (small[s_index] == '\0')
				return (final + index);
		}
		index ++;
	}
	return (NULL);
}
