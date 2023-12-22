/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:11:33 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/22 18:59:28 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_memcpy(void *dest, const void *src, size_t len);
char 	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
#endif
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2147483648
#endif