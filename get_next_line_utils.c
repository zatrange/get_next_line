/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:55:26 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/21 18:03:33 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tempd;
	const char	*temps;
	size_t		x;

	tempd = (char *)dest;
	temps = (const char *)src;
	x = 0;
	if (!dest && !src)
		return (0);
	while (tempd != temps && x < n)
	{
		tempd[x] = temps[x];
		x++;
	}
	return (dest);
}
char *ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	x;
	
	x = 0;
	if(!s1 || !s2)
		return (NULL);
	joined = (char *)malloc((ft_strlen(s1) 
			+ ft_strlen(s2) + 1) * sizeof(char));
	if(!joined)
		return (NULL);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(joined + ft_strlen(s1), s2, ft_strlen(s2));
	joined[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (joined);
}
char	*ft_strchr(const char *str, int c)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if(str[x] == c)
			return ((char *)&str[x]);
		x++;
	}
	if(str[x] == c)
		return ((char *)&str[x]);
	return(0);
}

void	*ft_calloc(size_t count , size_t size)
{
	char	*str;
	size_t	x;

	if ((int)count < 0 && (int)size < 0)
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
