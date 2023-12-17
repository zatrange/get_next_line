/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:54:22 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/17 20:54:07 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// static char *joined(char *buffer, char *temp)
// {
// 	char *tp;
	
// 	tp = strjoin(buffer, temp);
// 	free(buffer);
// 	return (tp);
// }
static char	*ft_readit(int fd, char *buffer)
{
	char *temp;
	int bytesread = 0;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return(NULL);
	while ((bytesread = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		if(bytesread < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[bytesread] = '\0';
		 buffer = strjoin(buffer, temp);
		 free(buffer);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	return (buffer);	
}

static char *lines(char *buffer)
{
	char *line;
	int x;
	
	x = 0;
	if (!buffer)
		return (NULL);
	while(buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	line = (char *)malloc((x + 2) * sizeof(char));
	if(!line)
		return (NULL);
	x = 0;
	while (x >= 0)
	{
		line[x] = buffer[x];
		x++;
	}
	buffer[x] ='\n';
	x++;
	buffer[x] = '\0'; 
	return(line);
}
char *get_next_line(int fd)
{
	static char	*buffer;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);	
	buffer = ft_strdup("");
	buffer = ft_readit(fd, buffer);
	line = lines(buffer);
	
	return (line);
}
int main()
{
	int fd = open("line.txt", O_RDONLY);	

	printf("<<<%s>>>", get_next_line(fd));	
	close(fd);
}
	
