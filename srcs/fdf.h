/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:21:55 by abravo            #+#    #+#             */
/*   Updated: 2022/12/10 23:51:44 by abravo           ###   ########.fr       */
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
# include "color.h"
# include <math.h>
# include <sys/time.h>

typedef struct s_pts
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_pts;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	scale;
	double	z_scale;
	float	z_max;
	float	z_min;
	double	win_x;
	double	win_y;
	int		mid_x;
	int		mid_y;
	double	size_x;
	double	size_y;
	double	angle;
	double	move_x;
	double	move_y; 
	t_pts	*center;
	t_pts	**matrix;
}			t_data;

int		check_file(const char *filename);
t_pts	**fill_matrix(const char *map, t_data *data);
void		count_lines(const char *map, t_data *data);
void	set_img(t_data *data);
double	step_color(t_pts from, t_pts to, t_pts *current);
int	default_color(t_data *data, int z);
void	draw_map(t_data *data);
void	ft_free_tab(void **tab);
char	*get_next_line(int fd);

float	ft_abs(int i);
void	min_z(t_data *data);
void	max_z(t_data *data);
int	ft_exit(t_data *data);
void	ft_error(t_data *data);
void ft_zscale(t_data *data);

#endif