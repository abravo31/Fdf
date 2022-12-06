/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:09:54 by abravo            #+#    #+#             */
/*   Updated: 2022/12/06 23:12:03 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	ft_free_tab(void **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	if (*tab == NULL)
		return ;
	while(tab && tab[i])
		free(tab[i++]);
	free(tab);
}

int	count_bytes(char *line)
{
	int		bytes;
	int		i;
	char	**line_nb;

	bytes = 0;
	i = 0;
	while(line[i] != '\n')
		i++;
	line[i] = '\0';
	line_nb = ft_split(line, ' ');
	if (!line_nb)
		return (0);
	while (line_nb[bytes])
		bytes++;
	ft_free_tab((void **)line_nb);
	return (bytes);
}

void	count_lines(const char *map, t_data *data)
{
	double	lines;
	int		fd;
	char	*line;

	lines = 0;
	fd = open(map, O_RDONLY);
	
	line = get_next_line(fd);
	data->size_x = count_bytes(line);
	// data->size_x = 0;
	if (data->size_x == 0)
	{
		free (line);
		printf("We see\n");
	}
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

void	fill_matrix_line(t_pts **matrix, char **tab, int y, int size)
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

t_pts	**fill_line(const char *map, int size, t_pts **matrix, int y)
{
	char	*line;
	char	**tab;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);

	while (line)
	{
		tab = ft_split(line, ' ');
		if (!tab)
		{
			printf("La doit tout free et sortir proprement\n");
			free(line);
			ft_free_tab((void **)matrix);
			return (NULL);
		}
		free(line);
		fill_matrix_line(matrix, tab, y, size);		
		line = get_next_line(fd);
		ft_free_tab((void **)tab);
		y++;
	}
	close(fd);
	matrix[y] = NULL;
	return (matrix);
}

t_pts	**fill_matrix(const char *map, t_data *data)
{
	t_pts	**matrix;
	int		i;
	
	i = 0;
	matrix = (t_pts **)malloc(sizeof(t_pts *) * (data->size_y + 1));
	if (!matrix)
	{
		//exit and free all
		return (NULL);
	}
	while (i < data->size_y)
		matrix[i++] = (t_pts *)malloc(sizeof(t_pts) * data->size_x);
		//proteger et free, sortir propement
	matrix = fill_line(map, data->size_x, matrix, 0);
	if (!matrix)
	{
		printf("Comment tu vas sortir\n");
		return (NULL);
	}
	return (matrix);
}
