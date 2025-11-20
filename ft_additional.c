/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:19:05 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/20 13:47:50 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;
	char	*copy;

	copy = (char *)s;
	if (ft_strlen(copy) <= start)
		return (ft_strdup(""));
	final = (char *)malloc(len + 1);
	if (final == NULL)
		return (NULL);
	ft_strlcpy(final, copy + start, len + 1);
	return (final);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*final;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = (char *)calloc(length, 1);
	if (final == NULL)
		return (NULL);
	i = 0;
	ft_strlcat(final, s1, length);
	ft_strlcat(final, s2, length);
	return (final);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	j = 0;
	final = (char *)malloc(ft_strlen(s1) + 1);
	while (s1[i])
	{
		if (ft_strchr(set, (int)s1[i]) == NULL)
		{
			final[j] = s1[i];
			j++;
		}
		i++;
	}
	final[j] = '\0';
	return (final);
}
