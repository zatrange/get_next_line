/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:54:22 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/17 18:17:27 by zgtaib           ###   ########.fr       */
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
static char *nextline(char *buffer)
{
	
}
char *get_next_line(int fd)
{
	static char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);	
	buffer = ft_strdup("");
	buffer = ft_readit(fd, buffer);
	
	return (buffer);
}
// int main()
// {
// 	int fd = open("line.txt", O_RDONLY);	

// 	printf("%s\n", get_next_line(fd));	
// 	close(fd);
// }
	
