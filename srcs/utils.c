/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:29:50 by abravo            #+#    #+#             */
/*   Updated: 2022/11/30 22:03:40 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	max_z(t_data *data)
{
    int x;
    int y;

    data->z_max = data->matrix[0][0].z
    y = 0;
    while(y < data->size_y)
    {
        x = 0;
        while(x < data->size_x)
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
    int x;
    int y;

    data->z_min = data->matrix[0][0].z
    y = 0;
    while(y < data->size_y)
    {
        x = 0;
        while(x < data->size_x)
        {
            if (data->z_min > data->matrix[y][x].z)
                data->z_min = data->matrix[y][x].z;
            x++;
        }
        y++;
    }
}