/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:13:58 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/26 17:31:18 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*chunks(char *buffer, char *temp)
{
	char	*hold;

	hold = ft_strjoin(buffer, temp);
	if (!hold)
		return (free(buffer), NULL);
	free(buffer);
	return (hold);
}

static char	*readbuffer(char *buffer, int fd)
{
	char	*temp;
	int		bytesread;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	bytesread = 1;
	temp = (char *)malloc(((size_t)(BUFFER_SIZE) + 1) * sizeof(char));
	if (!temp)
		return (free(buffer), NULL);
	while (bytesread > 0)
	{
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(temp), free(buffer), NULL);
		temp[bytesread] = '\0';
		buffer = chunks(buffer, temp);
		if (!buffer)
			return (free(temp), free(buffer), NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	free(temp);
	return (buffer);
}

static char	*remainder(char *buffer)
{
	int		x;
	char	*remains;
	int		len;

	x = 0;
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if (!buffer[x])
		return (free(buffer), NULL);
	len = ft_strlen(buffer) - x;
	remains = ft_calloc(len + 1, sizeof(char));
	if (!remains)
		return (free(buffer), NULL);
	x++;
	ft_memcpy(remains, buffer + x, len);
	free(buffer);
	return (remains);
}

static char	*lines(char *buffer)
{
	int		x;
	char	*line;

	x = 0;
	if (!buffer[x])
		return (NULL);
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if (buffer[x] == '\n')
		x++;
	line = ft_calloc(x + 1, sizeof(char));
	if (!line)
		return (NULL);
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

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = readbuffer(buffer, fd);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = lines(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = remainder(buffer);
	return (line);
}
