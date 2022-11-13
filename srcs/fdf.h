/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:21:55 by abravo            #+#    #+#             */
/*   Updated: 2022/11/13 20:31:20 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_data
{
    void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int endian;
}	t_data;

typedef struct		s_vector
{
	double		x;
	double		y;
	double		z;
	//int			color;
}					t_vector;

int check_file(const char *filename);
int    **fill_matrix(const char *map);
int count_bites(const char *map);
int count_lines(const char *map);
void draw_bites_map(int size_x, int size_y);

#endif