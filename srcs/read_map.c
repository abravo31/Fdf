/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:09:54 by abravo            #+#    #+#             */
/*   Updated: 2022/12/10 23:55:02 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

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

t_pts	**fill_line(const char *map, t_data *data, int y)
{
	char	*line;
	char	**tab;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		tab = ft_split(line, ' ');
		if (!tab)
		{
			free(line);
			ft_error(data);
		}
		free(line);
		fill_matrix_line(data->matrix, tab, y, data->size_x);		
		line = get_next_line(fd);
		ft_free_tab((void **)tab);
		y++;
	}
	close(fd);
	data->matrix[y] = NULL;
	return (data->matrix);
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
		if(!data->matrix[i])
			ft_error(data);
		i++;
	}	
	fill_line(map, data, 0);
	if (!data->matrix)
		ft_error(data);
	return (data->matrix);
}
