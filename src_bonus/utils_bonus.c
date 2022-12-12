/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:29:50 by abravo            #+#    #+#             */
/*   Updated: 2022/12/11 21:48:47 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(void **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	if (*tab == NULL)
		return ;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

float	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	ft_error(t_data *data)
{
	write(1, "Malloc failed.\n", 16);
	ft_exit(data);
}

void	count_bytes(char *line, t_data *data)
{
	int		bytes;
	int		i;
	char	**line_nb;

	bytes = 0;
	i = 0;
	while (line[i] != '\n')
		i++;
	line[i] = '\0';
	line_nb = ft_split(line, ' ');
	if (!line_nb)
		exit(1);
	while (line_nb[bytes])
		bytes++;
	ft_free_tab((void **)line_nb);
	data->size_x = bytes;
}

void	count_lines(const char *map, t_data *data)
{
	double	lines;
	int		fd;
	char	*line;

	lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
	{
		write(1, "Problem with file.\n", 20);
		exit(1);
	}
	count_bytes(line, data);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	data->size_y = lines;
	close(fd);
	free(line);
}
