/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:14:01 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/26 16:25:37 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*tempd;
	const char	*temps;
	size_t		x;

	if (!dest && !src)
		return (NULL);
	tempd = (char *)dest;
	temps = (const char *)src;
	x = 0;
	while (tempd != temps && x < len)
	{
		tempd[x] = temps[x];
		x++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = ft_calloc(len, 1);
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(joined + ft_strlen(s1), s2, ft_strlen(s2));
	return (joined);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	x;

	if ((int)count < 0 && (int)(size) < 0)
		return (NULL);
	x = 0;
	str = (char *)malloc((count * size) * sizeof(char));
	if (!str)
		return (NULL);
	while (x < (count * size))
	{
		str[x] = '\0';
		x++;
	}
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	i;
	int		x;

	i = (char)c;
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == i)
			return ((char *)&str[x]);
		x++;
	}
	if (str[x] == i)
		return ((char *)&str[x]);
	return (0);
}
