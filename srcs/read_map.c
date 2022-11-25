/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:09:54 by abravo            #+#    #+#             */
/*   Updated: 2022/11/24 20:56:16 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int count_bites(const char *map)
{
    char    *line;
    int bites;
    int fd;
    char    **line_nb;
    
    bites = 0;
    fd = open(map, O_RDONLY);
    line = get_next_line(fd);
    line[ft_strlen(line) - 1] = '\0';
    line_nb = ft_split(line, ' ');
    while (line_nb[bites])
        bites++;
    close(fd);
    return(bites);
}

int count_lines(const char *map)
{
    int lines;
    int fd;
    char *line;

    lines = 0;
    fd = open(map, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        line = get_next_line(fd);
        lines++;
    }
    close(fd);
    return (lines);
}

t_pts	**fill_line(const char *map, int size, t_pts **matrix)
{
	char    *line;
    char    **tab;
	int		y;
    int		x;
    int fd;

	fd = open(map, O_RDONLY);
    y = 0;
    line = get_next_line(fd);
	while (line)
	{
        x = 0;
        tab = ft_split(line, ' ');
        while(x < size)
        {
            matrix[y][x].z = ft_atoi(tab[x]);
            matrix[y][x].x = x;
            matrix[y][x].y = y;
            x++;
        }
        line = get_next_line(fd);
		y++;
	}
    close(fd);
	matrix[y] = NULL;
	return (matrix);
}

t_pts   **fill_matrix(const char *map)
{
   t_pts  **matrix;
   int  x;
   int  y;
   int  i;

    x = count_bites(map);
    y = count_lines(map);
    i = 0;
    matrix = (t_pts **)malloc(sizeof(t_pts *) * (y + 1) );
    while (i < y)
        matrix[i++] = (t_pts *)malloc(sizeof(t_pts) * x);
    if (!matrix)
        return(NULL);
    matrix = fill_line(map, x, matrix);
    return (matrix);
}