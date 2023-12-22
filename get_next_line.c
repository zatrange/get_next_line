/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:13:58 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/22 18:50:26 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

static char *chunks(char *buffer, char *temp)
{
	char	*hold;
	
	if(!buffer)
	{
		free(temp);
		return (NULL);
	}
	hold = ft_strjoin(buffer, temp);
	if(!hold)
	{
		free(buffer);
		return(NULL);
	}
	free(buffer);
	return(hold);
}
static char	*readbuffer(char *buffer, int fd)
{
	char	*temp;
	int		bytesread;
	
	if (!buffer)
		buffer = ft_calloc(1, 1);
	bytesread = 5;
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
	{	
		free(buffer);
		return(NULL);
	}
	while (bytesread > 0)
	{
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(temp);
			return(NULL);
		}
		temp[bytesread] = '\0';
		buffer = chunks(buffer, temp);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}                       
	free(temp);
	return (buffer);
}
static char	*remainder(char *buffer)
{
	int		x;
	int		y;
	char	*remains;
	int		len;

	x = 0;
	if(!buffer || !buffer[x])
	{	
		free(buffer);
		return (NULL);
	}
	y = 0;
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	len = ft_strlen(buffer) - x;
	remains = ft_calloc(len + 1, 1);
	if(!remains)
	{
		free(buffer);
		return (NULL);
	}
	x++;
	while (y < len)
	{
		remains[y] = buffer[x];
		x++;
		y++;
	}
	free(buffer);
	return (remains);
}	
static char	*lines(char *buffer)
{
	int		x;
	char	*line;

	x = 0;
	if(!buffer || !buffer[x])
		return (NULL);
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if(buffer[x] == '\n')
		x++;
	line = ft_calloc(x + 1, 1);
	x = 0;
	while (buffer[x] != '\0')
	{
		line[x] = buffer[x];
		if (line[x] == '\n')
		{
			x++;
			break ;
		}
		x++;
	}
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE >= 2147483647)
	{
		free(buffer);
		return (NULL);
	}
	buffer = readbuffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = lines(buffer);
	buffer = remainder(buffer);
	return (line);
}
