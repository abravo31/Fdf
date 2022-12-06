/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:06:18 by abravo            #+#    #+#             */
/*   Updated: 2022/12/06 20:18:39 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


double	ft_percent(int start, int end, int current)
{
	double	cur_place;
	double	dist;

	cur_place = current - start;
	dist = end - start;
	
	if (dist == 0)
		return (1);
	return (cur_place / dist);
}

int	default_color(t_data *data, int z)
{
	double	percent;

	percent = ft_percent(data->z_max, data->z_min, z);
	if (percent < 0.2)
		return (COLOR_DISCO);
	else if (percent < 0.4)
		return (COLOR_BRICK_RED);
	else if (percent < 0.6)
		return (COLOR_FLAMINGO);
	else if (percent < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int	get_color(float percent, int start, int end)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - percent) * ((start >> 16) & 0xFF) + percent
			* ((end >> 16) & 0xFF));
	g = (int)((1 - percent) * ((start >> 8) & 0xFF) + percent
			* ((end >> 8) & 0xFF));
	b = (int)((1 - percent) * ((start) & 0xFF) + percent
			* ((end) & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

double	step_color(t_pts from, t_pts to, t_pts *current)
{
	double	percent;
	double	step_color;

	if (ft_abs(from.x - to.x) > ft_abs(from.y - to.y))
		percent = ft_percent(from.x, to.x, current->x);
	else
		percent = ft_percent(from.y, to.y, current->y);
	step_color = get_color(percent, from.color, to.color);
	return (step_color);
}