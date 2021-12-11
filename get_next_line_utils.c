/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:18:34 by aoukhart          #+#    #+#             */
/*   Updated: 2021/12/11 02:48:52 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	cat = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!cat)
		return (NULL);
	while (s1[++i])
		cat[i] = s1[i];
	j = i;
	i = 0;
	while (s2[i])
		cat[j++] = s2[i++];
	free(s1);
	return (cat);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*copy;
	size_t	i;

	i = 0;
	copy = malloc(count * size);
	if (!copy)
		return (NULL);
	while (i < count)
	{
		*(unsigned char *)(copy + i) = '\0';
		i++;
	}
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
