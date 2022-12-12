/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:29:00 by abravo            #+#    #+#             */
/*   Updated: 2022/12/11 21:55:59 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, t_pts *cur, t_pts from, t_pts to)
{
	int	dst;
	int	color;

	if (cur->x >= 0 && cur->x <= 1920 && cur->y >= 0 && cur->y <= 1080)
	{
		dst = ((int)cur->y * data->line_len) + ((int)cur->x * (data->bpp / 8));
		color = step_color(from, to, cur);
		data->addr[dst] = color;
		data->addr[++dst] = color >> 8;
		data->addr[++dst] = color >> 16;
	}
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

Bool	draw_line(t_data *data, t_pts from, t_pts to)
{
	float	step_x;
	float	step_y;
	float	step;
	t_pts	*cur;
	int		i;

	cur = malloc(sizeof (t_pts));
	if (!cur)
		return (False);
	step_x = to.x - from.x;
	step_y = to.y - from.y;
	step = ft_step(step_x, step_y);
	step_x /= step;
	step_y /= step;
	cur->x = from.x;
	cur->y = from.y;
	i = 0;
	while (++i <= (int)step)
	{
		my_mlx_pixel_put(data, cur, from, to);
		cur->x += step_x;
		cur->y += step_y;
	}
	free(cur);
	return (True);
}

void	draw_map(t_data *data, int x, int y)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->addr = mlx_get_data_addr(data->img,
			&(data->bpp), &(data->line_len), &(data->endian));
	set_img(data);
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (x + 1 != data->size_x)
				if (draw_line(data, data->matrix[y][x],
					data->matrix[y][x + 1]) == 0)
					ft_error(data);
			if (y + 1 != data->size_y)
				if (draw_line(data, data->matrix[y][x],
					data->matrix[y + 1][x]) == 0)
					ft_error(data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
