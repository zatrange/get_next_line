/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:54:22 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/21 17:25:08 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char *joined(char *buffer, char *temp)
{
	char *tp;
	tp = ft_strjoin(buffer, temp);
	if(!tp)
	{
		free(buffer);
		return(NULL);
	}
	free(buffer);
	return (tp);
}
static char	*ft_readit(int fd, char *buffer)
{
	char *temp;
	int bytesread = 1;
		if (!buffer)
			buffer = ft_calloc(1, 1);
		if(!buffer)
			return(NULL);
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
		 buffer = joined(buffer, temp);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}                       
	// printf(" \n||%s||\n ", buffer);
	free(temp);
	return (buffer);
}
static char *next(char *buffer)
{
	int		x;
	char	*remains;
	int		y;
	
	
	x = 0;
	y = 0;
	if(!buffer || !buffer[x])
	{
		free(buffer);
		return (NULL);
	}	
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
		int len = ft_strlen(buffer) - x;
	remains = (char *)malloc((len + 1) * sizeof(char));
	x++;
	if (!remains)
	{	
		free(buffer);
		return (NULL);
	}
	// printf("\n--%s--\n", buffer);
	while (y < len)
	{
		remains[y] = buffer[x];
		x++;
		y++;
	}
	remains[y] = '\0';
	// printf("\n<<%p>>\n", remains);
	free(buffer);
	return (remains);
}
static char *lines(char *buffer)
{
	char *line;
	int x;
	
	x = 0;
	if (!buffer || !buffer[x])
		return (NULL);
	while(buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if (buffer[x] == '\n')
		x++;
	line = ft_calloc(x + 1, 1);
	x = 0;
	while (buffer[x] != '\0')
	{
		line[x] = buffer[x];
		if (line[x] == '\n')
		{
			x++;
			break;
		}
		x++;
	}
	// printf("\n----%p----\n", line);
	return(line);
}
char *get_next_line(int fd)
{
	static char	*buffer;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{	
		free(buffer);
		return (NULL);
	}
	buffer = ft_readit(fd, buffer);
	if (!buffer)
		return (NULL);
	line = lines(buffer);
	buffer = next(buffer);
	// printf("<%p>\n", line);
	return (line);
}
void f()
{
	system("leaks a.out");
}


// int main()
// {
// 	// atexit(f);
// 	int fd = open("line.txt", O_RDONLY);
// 	char *lol;
// 	int x = 0;
// 	int line = 7;
// 	// lol = get_next_line(fd);
// 	// printf("<<%s>>\n",lol);
// 	// free(lol);
// 	// printf("\n-------------------------------------------\n");
// 	// 	lol = get_next_line(fd);
// 	// printf("<<%s>>\n",lol);
// 	// free(lol);
// 	// printf("\n-------------------------------------------\n");
// 	// 	lol = get_next_line(fd);
// 	// printf("<<%s>>\n",lol);
// 	// free(lol);
// 	// printf("\n-------------------------------------------\n");
// 	// 	lol = get_next_line(fd);
// 	// printf("<<%s>>\n",lol);
// 	// free(lol);
// 	// printf("\n-------------------------------------------\n");
// 	while (x < line && (lol = get_next_line(fd))!= NULL)
// 	{
// 		printf("%s", lol);
// 		free(lol);
// 		x++;
// 	}
// 	close(fd);
// }
	
