/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:15:11 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/25 20:12:46 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *chunks(char *buffer, char *temp)
{
	char	*hold;
	// printf("\n--%p--\n", buffer);
	hold = ft_strjoin(buffer, temp);
	if(!hold)
		return(free(buffer), buffer = NULL, NULL);
	free(buffer);
	return(hold);
}
static char	*readbuffer(char *buffer, int fd)
{
	char	*temp;
	int		bytesread;
	
	if (!buffer)
		buffer = ft_calloc(1, 1);
	bytesread = 1;
	temp = (char *)malloc(((size_t)(BUFFER_SIZE) + 1) * sizeof(char));
	if(!temp)
		return (free(buffer), buffer = NULL, NULL);
	while (bytesread > 0)
	{
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread == -1)
			return (free(temp), free(buffer), buffer = NULL, NULL);
		temp[bytesread] = '\0';
		buffer = chunks(buffer, temp);
		if (!buffer)
			return (free(temp), free(buffer), buffer = NULL, NULL);		
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
	if(!buffer[x])
	{	
		free(buffer);
		return (NULL);
	}
	len = ft_strlen(buffer) - x;
	remains = ft_calloc(len + 1, sizeof(char));
	if(!remains)
		return(free(buffer), buffer = NULL, NULL);
	x++;
	ft_memcpy(remains, buffer + x, len);
	free(buffer);
	buffer = NULL;
	return (remains);
}	
static char	*lines(char *buffer)
{
	int		x;
	char	*line;

	x = 0; 
	if(!buffer[x])
		return (NULL);
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if(buffer[x] == '\n')
		x++;
	line = ft_calloc(x + 1, sizeof(char));
	if(!line)
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
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer[fd] = readbuffer(buffer[fd], fd);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		return(NULL);
	}
	line = lines(buffer[fd]);
	if (!line)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = remainder(buffer[fd]);
	return (line);
}