/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgtaib <zgtaib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:15:49 by zgtaib            #+#    #+#             */
/*   Updated: 2023/12/25 18:06:50 by zgtaib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h> 
# include <fcntl.h>
# include <limits.h>
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
char 	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
#endif
#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif
