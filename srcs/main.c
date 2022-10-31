/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:25 by abravo            #+#    #+#             */
/*   Updated: 2022/10/31 21:41:56 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	printf("[%d, %d, %d, %d]\n", x, y, data->line_length, data->bits_per_pixel);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_exit()
{
	exit(1);
}

int	key_hook(int key)
{
	//printf("[%d]\n", key);
	if (key == 65307)
		exit(1);
	return (0);
}

float	ft_abs(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void draw_line_yo(t_data img, float x1, float y1, float x2, float y2)
{
  float x;
  float y;
  float	dx, dy, step;
  int	i;
  
  dx = (x2 - x1);
  dy = (y2 - y1);
  if (ft_abs(dx) >= ft_abs(dy))
    step = ft_abs(dx);
  else
    step = ft_abs(dy);
  dx = dx / step;
  dy = dy / step;
  x = x1;
  y = y1;
  i = 1;
  while (i <= step) 
  {
    my_mlx_pixel_put(&img, x, y, 0x00FF0000);
    x = x + dx;
    y = y + dy;
    i = i + 1;
  }
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	if (button == 1)
	{
		if (img->prev_x == 0)
		{
			img->prev_x = x;
			img->prev_y = y;
		}
		else
		{
			draw_line_yo(*img, x, y, img->prev_x, img->prev_y);
			img->prev_x = 0;
			img->prev_y = 0;
		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	if(ac != 2 || check_file(av[1]))
		return (1);
	t_data	img;
	
	img.prev_x = 0;
	img.prev_y = 0;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello word!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//draw_line_yo(img, 10, 10, 100, 100);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	/*mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 20);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 10);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 20);*/
	mlx_mouse_hook(img.mlx_win, mouse_hook, &img);
	mlx_hook(img.mlx_win, 17, 0, ft_exit, NULL);
	mlx_key_hook(img.mlx_win, key_hook, NULL);
	mlx_loop(img.mlx);
	mlx_destroy_window(img.mlx, img.mlx_win);
	//mlx_destroy_image(mlx, img);
}
