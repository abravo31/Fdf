/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:11:12 by abravo            #+#    #+#             */
/*   Updated: 2022/11/30 22:25:20 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	zoom(t_data *data, int x, int y)
{
//	printf("x: %f\n", pt->x);
	data->matrix[y][x].x *= data->scale;
//	printf("y: %f scale: %f\n", pt->x, data->scale);
	data->matrix[y][x].y *= data->scale;
	data->matrix[y][x].z *= data->z_scale;
}

void	isometric(t_data *data, t_pts *pt)
{
	double	tmp_x;

	pt->x -= data->size_x / 2 * data->scale;
	pt->y -= data->size_y / 2 * data->scale;
	tmp_x = pt->x;
	pt->x = (pt->x - pt->y) * cos(data->angle);
	pt->y = (tmp_x + pt->y) * sin(data->angle) - pt->z;
}

void	set_img(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->size_y)
	{
		x = -1;
		while (++x < data->size_x)
		{
			get_color(data, data->matrix[y][x].z)
			zoom(data, x, y);
			isometric(data, &data->matrix[y][x]);
			data->matrix[y][x].x += data->mid_x;
			data->matrix[y][x].y += data->mid_y;
		}
	}
}
