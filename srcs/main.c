/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:25 by abravo            #+#    #+#             */
/*   Updated: 2022/11/21 22:55:45 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	set_data(t_data *img)
{
	img->scale = 50;
	img->z_scale = 10;
	//img->is_isometric = 1;
	img->angle = 0.523599;
	img->win_x = 1920;
	img->win_y = 1080;
	img->mid_x = img->win_x / 2;
	img->mid_y = img->win_y / 2;
	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->mlx_win = mlx_new_window(img->mlx, img->win_x, img->win_y, "FDF");
}

int	main(int ac, char **av)
{
	t_data	img;
	int	size_x;
	int size_y;
	
	if(ac != 2 || check_file(av[1]))
		return (1);
	img.matrix = fill_matrix(av[1]);
	set_data(&img);
	size_x = count_bites(av[1]);
	size_y = count_lines(av[1]);
	draw_bites_map(size_x, size_y, &img);
	
	//draw_line_yo(img, 10, 10, 100, 100);
	/*mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 20);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 10);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 20);*/

	//mlx_destroy_image(mlx, img);
}
