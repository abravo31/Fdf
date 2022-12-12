/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:09:54 by abravo            #+#    #+#             */
/*   Updated: 2022/12/11 21:56:08 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix_line(t_pts **matrix, char **tab, int y, double size)
{
	int	x;

	x = 0;
	while (x < size)
	{
		matrix[y][x].z = ft_atoi(tab[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		x++;
	}
}

char	**split_line(char *line, t_data *data)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab)
	{
		free(line);
		ft_error(data);
	}
	return (tab);
}

void	fill_line(const char *map, t_data *data, int y)
{
	char	*line;
	char	**tab;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (!line)
		return ;
	while (line)
	{
		tab = split_line(line, data);
		free(line);
		fill_matrix_line(data->matrix, tab, y, data->size_x);
		line = get_next_line(fd);
		ft_free_tab((void **)tab);
		y++;
	}
	close(fd);
	data->matrix[y] = NULL;
}

t_pts	**fill_matrix(const char *map, t_data *data)
{
	int		i;

	i = 0;
	data->matrix = (t_pts **)malloc(sizeof(t_pts *) * (data->size_y + 1));
	if (!data->matrix)
		ft_error(data);
	while (i < data->size_y)
	{
		data->matrix[i] = (t_pts *)malloc(sizeof(t_pts) * data->size_x);
		if (!data->matrix[i])
			ft_error(data);
		i++;
	}	
	fill_line(map, data, 0);
	if (!data->matrix)
		ft_error(data);
	return (data->matrix);
}
