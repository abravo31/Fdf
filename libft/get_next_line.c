/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:45:26 by abravo            #+#    #+#             */
/*   Updated: 2022/12/11 21:16:03 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_buf(char *buf, int new_size)
{
	int		i;
	int		len_nl;

	i = 0;
	len_nl = ft_strlen(&buf[new_size]);
	if (len_nl)
		ft_memcpy(buf, &buf[new_size], len_nl);
	while ((i + len_nl) < BUFFER_SIZE && buf[i + len_nl])
	{
		buf[i + len_nl] = '\0';
		i++;
	}
	return (buf);
}

char	*ft_get_line(char *buf, char *line_read)
{
	int		i;
	int		line_len;
	char	*store;

	line_len = ft_strlen(line_read);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	store = (char *)malloc(sizeof(char) * (line_len + i + 1));
	if (!store)
		return (NULL);
	store[line_len + i] = '\0';
	ft_memcpy(store, line_read, line_len);
	ft_memcpy(&store[line_len], buf, i);
	ft_new_buf(buf, i);
	if (line_read)
		free(line_read);
	line_read = NULL;
	return (store);
}

int	ft_found_nl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*store;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	bytes = 1;
	store = NULL;
	while (ft_found_nl(store) == 0 && bytes != 0)
	{
		if (!buf[0])
		{
			bytes = read(fd, buf, BUFFER_SIZE);
			buf[bytes] = '\0';
		}
		store = ft_get_line(buf, store);
		if (!store)
			break ;
	}
	if (!store || !store[0])
	{
		free(store);
		return (NULL);
	}
	return (store);
}
