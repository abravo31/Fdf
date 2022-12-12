/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:46:03 by abravo            #+#    #+#             */
/*   Updated: 2022/12/11 20:58:35 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*get_next_line(int fd);
char		*ft_get_line(char *buf, char *line_read);
char		*ft_new_buf(char *buf, int new_size);
int			ft_found_nl(char *str);

#endif
