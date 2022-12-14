/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:25 by abravo            #+#    #+#             */
/*   Updated: 2022/12/11 21:24:09 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	ft_free_tab((void **)data->matrix);
	free(data->mlx);
	exit(1);
}

void	set_data(t_data *data)
{
	data->angle = 0.523599;
	data->win_x = 1920;
	data->win_y = 1080;
	data->mid_x = data->win_x / 2;
	data->mid_y = data->win_y / 2;
	data->move_x = 0;
	data->move_y = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_x, data->win_y, "FDF");
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
			&data->endian);
	data->scale = data->win_x / data->size_x * 0.4;
	data->z_scale = 1;
	data->matrix = NULL;
}

int	key_hook(int key, t_data *data)
{
	if (key == 65451)
		data->scale += 5;
	if (key == 65453)
		data->scale -= 5;
	if (key == 65362)
		data->move_y -= 5;
	if (key == 65364)
		data->move_y += 5;
	if (key == 65363)
		data->move_x += 5;
	if (key == 65361)
		data->move_x -= 5;
	if (key == 65307)
		ft_exit(data);
	ft_reset(data);
	draw_map(data, 0, 0);
	return (0);
}

void	setup_controls(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || check_file(av[1]))
		return (1);
	count_lines(av[1], &data);
	set_data(&data);
	fill_matrix(av[1], &data);
	max_z(&data);
	min_z(&data);
	ft_zscale(&data);
	setup_controls(&data);
	draw_map(&data, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
