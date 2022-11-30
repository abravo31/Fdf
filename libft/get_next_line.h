/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:46:03 by abravo            #+#    #+#             */
/*   Updated: 2022/11/28 20:40:19 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

char		*ft_strchr(const char *s, int c);
char		*ft_strjoin_gnl(char *s1, char const *s2);
char		*ft_read_and_store(int fd, char *store);
char		*get_next_line(int fd);
char		*ft_get_line(char *store);
char		*ft_store(char *store);

#endif
