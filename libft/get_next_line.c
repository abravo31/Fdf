/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:45:26 by abravo            #+#    #+#             */
/*   Updated: 2022/11/28 16:17:09 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_store(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	new_store = (char *)malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!new_store)
		return (NULL);
	i += 1;
	j = 0;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = '\0';
	if (store)
		free(store);
	return (new_store);
}

char	*ft_get_line(char *store)
{
	int		i;
	char	*line;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (store[++i] && store [i] != '\n')
		line[i] = store[i];
	if (store[i] == '\n')
	{
		line[i] = store[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_and_store(int fd, char *store)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			bytes;

	bytes = 1;
	while (ft_strchr(store, '\n') == NULL && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buf[bytes] = '\0';
		tmp = store;
		store = ft_strjoin_gnl(store, buf);
		free(tmp);
	}
	return (store);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	char		*store;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	store = ft_strjoin_gnl(NULL, buf);
	store = ft_read_and_store(fd, store);
	if (!store)
		return (NULL);
	line = ft_get_line(store);
	store = ft_store(store);
	i = 0;
	while (store && store[i])
	{
		buf[i] = store[i];
		i++;
	}
	buf[i] = '\0';
	free (store);
	return (line);
}

/*int	main()
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("-%s", line);
	free (line);
	// line = get_next_line(fd);
	// printf("-%s", line);
	// free (line);
	// line = get_next_line(fd);
	// printf("-%s", line);
	// free (line);
	// line = get_next_line(fd);
	// printf("-%s", line);
	// free (line);
	// line = get_next_line(fd);
	// printf("-%s", line);
	// free (line);
	// line = get_next_line(fd);
	// printf("-%s", line);
	// free (line);
	// line = get_next_line(fd);
	// printf("-%s", line);
	// free (line);
	// line = get_next_line(fd);
	// printf("-%s", line);
	// free (line);
	// free (line);
	// line = get_next_line(fd);
	// printf("%s", line);
	//while (line)
	//{
	//	printf("%s", line);
	//	free (line);
	//	line = get_next_line (fd);
	//}

	close (fd);
	return (0);
}*/
