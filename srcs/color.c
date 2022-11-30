/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:06:18 by abravo            #+#    #+#             */
/*   Updated: 2022/11/30 22:17:32 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	default_color(t_data *data)
{
	float	percent;

	percent = ft_percentage(data->z_max, data->z_min, data->matrix);
	if (percent < 0.25)
		return (make_color(ft_percentage(0, 250, percent * 1000),
				BLUE, PURPLE));
	else if (percent < 0.5)
		return (make_color(ft_percentage(0, 500, percent * 1000),
				PURPLE, PINK));
	else if (percent < 0.75)
		return (make_color(ft_percentage(0, 750, percent * 1000),
				PINK, RED));
	else
		return (make_color(ft_percentage(0, 1000, percent * 1000),
				RED, YELLOW));
}