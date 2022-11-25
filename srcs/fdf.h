/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:21:55 by abravo            #+#    #+#             */
/*   Updated: 2022/11/24 22:07:07 by abravo           ###   ########.fr       */
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
# include <math.h>

typedef struct s_pts
{
	double	x;
	double	y;
	double	z;
}			t_pts;

typedef struct s_data
{
    void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
	int 	scale;
	int		z_scale;
	int		win_x;
	int		win_y;
	int		mid_x;
	int		mid_y;
	int	size_x;
	int	size_y;
	double	angle;
	t_pts	*center;
	t_pts	**matrix;
}			t_data;


int check_file(const char *filename);
t_pts    **fill_matrix(const char *map);
int count_bites(const char *map);
int count_lines(const char *map);
void draw_bites_map(t_data *data);

#endif