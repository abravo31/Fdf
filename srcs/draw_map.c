/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:29:00 by abravo            #+#    #+#             */
/*   Updated: 2022/11/13 21:30:33 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_exit()
{
	exit(1);
}

int	key_hook(int key)
{
	if (key == 65307)
		exit(0);
	return (0);
}

float	ft_abs(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float ft_step(float dx, float dy)
{
  float step;
  
  step = 0;
  if (ft_abs(dx) >= ft_abs(dy))
    step = ft_abs(dx);
  else
    step = ft_abs(dy);
  return(step);
}

void draw_line(t_data img, float x1, float y1, float x2, float y2)
{
  float x;
  float y;
  float	dx;
  float dy;
  float step;
  int	i;
  
  dx = (x2 - x1);
  dy = (y2 - y1);
  step = ft_step(dx, dy);
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

t_vector	rotate(double x, double y, double z)
{
	t_vector	v;

	v.x = cos(0.785) * x + sin(0.785) * z;
	v.z = -sin(0.785) * x + cos(0.785) * z;
	y = p.y;
	z = v.z;
	v.y = cos(1.047) * y - sin(1.047) * z;
	v.z = sin(1.047) * y + cos(1.047) * z;
	//v.color = p.color;
	return (v);
}

void draw_bites_map(int size_x, int size_y)
{
  t_data  img;
  int x;
  int y;
  int z;

  x = 0;
  y = 0;
  z = matrix[y][x];
  img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "fdf");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

  while (y < size_y)
  {
    while(x < size_x)
    {
      my_mlx_pixel_put(&img, x*50, y*50, 0x00FF0000);
        if (x + 1 != size_x)
          draw_line(img, x*50, y*50, (x+1)*50, y*50);
        if (y + 1 != size_y)
          draw_line(img, x*50, y*50, x*50, (y+1)*50);
      p.x++; 
    }
    x = 0;
    y++;
  }
  mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 17, 0, ft_exit, NULL);
	mlx_key_hook(img.mlx_win, key_hook, NULL);
	mlx_loop(img.mlx);
	mlx_destroy_window(img.mlx, img.mlx_win);
}

