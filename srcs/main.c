/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:25 by abravo            #+#    #+#             */
/*   Updated: 2022/11/25 18:17:17 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	init_center(t_data *data)
{
	data->center->x = data->size_x / 2;
	data->center->y = data->size_y / 2;
	data->center->z = 0;
}

void	set_data(t_data *data, char *file)
{
	data->scale = 50;
	data->z_scale = 20;
	//img->is_isometric = 1;
	data->angle = 0.523599;
	data->win_x = 1920;
	data->win_y = 1080;
	data->mid_x = data->win_x / 2;
	data->mid_y = data->win_y / 2;
	data->size_x = count_bites(file);
	data->size_y = count_lines(file);
	//printf("%d, %d\n", data->size_x, data->size_y);
	//data->center = malloc(sizeof(t_pts));
	//printf("test\n");
	//protect malloc;
	//init_center(data);
	data->mlx = mlx_init();
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->mlx_win = mlx_new_window(data->mlx, data->win_x, data->win_y, "FDF");
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	if(ac != 2 || check_file(av[1]))
		return (1);
	data = malloc(sizeof (t_data));
	set_data(data, av[1]);
	data->matrix = fill_matrix(av[1]);
	printf("test2\n");
	draw_bites_map(data);
	return (0);
}
