/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:47:54 by abravo            #+#    #+#             */
/*   Updated: 2022/12/11 21:48:23 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	max_z(t_data *data)
{
	int	x;
	int	y;

	data->z_max = data->matrix[0][0].z;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (data->z_max < data->matrix[y][x].z)
				data->z_max = data->matrix[y][x].z;
			x++;
		}
		y++;
	}
}

void	min_z(t_data *data)
{
	int	x;
	int	y;

	data->z_min = data->matrix[0][0].z;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (data->z_min > data->matrix[y][x].z)
				data->z_min = data->matrix[y][x].z;
			x++;
		}
		y++;
	}
}

void	ft_zscale(t_data *data)
{
	if (data->z_max <= 20)
		data->z_scale = 10;
	else
		data->z_scale *= 0.4;
}
