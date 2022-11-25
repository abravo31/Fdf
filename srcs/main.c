/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:25 by abravo            #+#    #+#             */
/*   Updated: 2022/11/25 19:44:31 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	ft_exit()
{
	exit(1);
}

int	key_hook(int key, t_data *data)
{
	if (key == 65307)
  {
    mlx_destroy_image(data->mlx, data->img);
	  mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
  }
	return (0);
}

void	set_data(t_data *data, char *file)
{
	data->angle = 0.523599;
	data->win_x = 1920;
	data->win_y = 1080;
	data->mid_x = data->win_x / 2;
	data->mid_y = data->win_y / 2;
	data->size_x = count_bites(file);
	data->size_y = count_lines(file);
	data->mlx = mlx_init();
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->mlx_win = mlx_new_window(data->mlx, data->win_x, data->win_y, "FDF");
	data->scale = data->win_x / data->size_x * 0.4;
	data->z_scale = 2;
}

int	main(int ac, char **av)
{
	t_data	data;
	
	if(ac != 2 || check_file(av[1]))
		return (1);
	//data = malloc(sizeof (t_data));
	set_data(&data, av[1]);
	data.matrix = fill_matrix(av[1]);
	printf("test2\n");
	draw_bites_map(&data);
	mlx_hook(data.mlx_win, 17, 0, ft_exit, NULL);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
