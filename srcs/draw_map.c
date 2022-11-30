/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:29:00 by abravo            #+#    #+#             */
/*   Updated: 2022/11/30 22:23:24 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	dst;

	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		dst = (y * data->line_length) + (x * (data->bpp / 8));
		data->addr[dst] = color;
		data->addr[++dst] = color >> 8;
		data->addr[++dst] = color >> 16;
		//*(unsigned int *)dst = color;
	}
}

float	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	ft_step(float dx, float dy)
{
	float	step;

	step = 0;
	if (ft_abs(dx) >= ft_abs(dy))
	step = ft_abs(dx);
	else
	step = ft_abs(dy);
	return (step);
}

// void	draw_line(t_data *data, t_pts from, t_pts to)
// {
// 	float	step_x;
// 	float	step_y;
// 	float	step;
// 	int		i;
// 	int		color;

// 	step_x = to.x - from.x;
// 	step_y = to.y - from.y;
// 	step = ft_step(step_x, step_y);
// 	step_x /= step;
// 	step_y /= step;
// 	i = 1;
// 	color = 0x00FF0000;
// 	while (i <= step)
// 	{
// 		my_mlx_pixel_put(data, from.x, from.y, color);
// 		from.x += step_x;
// 		from.y += step_y;
// 		i++;
// 	}
// }

void	draw_line(t_data *data, t_pts from, t_pts to)
{
	float	step_x;
	float	step_y;
	float	step;
	int		i;

	step_x = to.x - from.x;
	step_y = to.y - from.y;
	step = ft_step(step_x, step_y);
	step_x /= step;
	step_y /= step;
	i = 1;
	while (i <= step)
	{
		my_mlx_pixel_put(data, from.x, from.y, get_color(pt, from, to));
		from.x += step_x;
		from.y += step_y;
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->addr = mlx_get_data_addr(data->img,
			&(data->bpp), &(data->line_length), &(data->endian));
	set_img(data);
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (x + 1 != data->size_x)
				draw_line(data, data->matrix[y][x], data->matrix[y][x + 1]);
			if (y + 1 != data->size_y)
				draw_line(data, data->matrix[y][x], data->matrix[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
