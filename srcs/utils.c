/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:29:50 by abravo            #+#    #+#             */
/*   Updated: 2022/12/10 23:53:14 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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

float	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	max_z(t_data *data)
{
    int x;
    int y;

    data->z_max = data->matrix[0][0].z;
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

    data->z_min = data->matrix[0][0].z;
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

void ft_zscale(t_data *data)
{
    if (data->z_max <= 20)
        data->z_scale = 10;
    else
        data->z_scale *= 0.4;
}