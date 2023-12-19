/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:55:26 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/19 13:13:28 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
char *strjoin(const char *s1, const char *s2)
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
	while (x < ft_strlen(s1))
	{
		joined[x] = s1[x];
		x++;
	}
	x = 0;
	while(x < ft_strlen(s2))
	{
		joined[ft_strlen(s1) + x] = s2[x];
		x++;
	}
	joined[ft_strlen(s1) + x] = '\0';
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
char	*ft_strdup(const char* str)
{
	int	x;
	char	*dup;

	x = 0;
	dup = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if(!dup)
		return(NULL);
	while (str[x] != '\0')
	{
		dup[x] = str[x];
		x++;
	}
	dup[x] = '\0';
	return(dup);
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
