/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:25 by abravo            #+#    #+#             */
/*   Updated: 2022/11/12 23:15:40 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	main(int ac, char **av)
{
	//int	**matrix;
	int	size_x;
	int size_y;
	
	if(ac != 2 || check_file(av[1]))
		return (1);
	fill_matrix(av[1]);
	size_x = count_bites(av[1]);
	size_y = count_lines(av[1]);
	draw_bites_map(size_x, size_y);
	
	//draw_line_yo(img, 10, 10, 100, 100);
	/*mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 20);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 10);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 20);*/

	//mlx_destroy_image(mlx, img);
}
