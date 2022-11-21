/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:29:00 by abravo            #+#    #+#             */
/*   Updated: 2022/11/21 23:00:18 by abravo           ###   ########.fr       */
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

void	zoom(t_pts *from, t_pts *to, t_data *img)
{
	from->x *= img->scale;
	from->y *= img->scale;
	to->x *= img->scale;
	to->y *= img->scale;
	from->z *= img->z_scale;
	to->z *= img->z_scale;
}

void	isometric(t_pts *pt, double angle)
{
	pt->x = (pt->x - pt->y) * cos(angle);
	pt->y = (pt->x + pt->y) * sin(angle) - pt->z;
}

void	set_img(t_pts *from, t_pts *to, t_data *img)
{
	zoom(from, to, img);
	isometric(from, img->angle);
	isometric(to, img->angle);
  from->x += img->mid_x - (20 / 2) * img->scale;
	from->y += img->mid_y - (10 / 2) * img->scale;
	to->x += img->mid_x - (20 / 2) * img->scale;
	to->y += img->mid_y - (10 / 2) * img->scale;
}

void draw_line(t_data *img, t_pts from, t_pts to)
{
  float step_x;
  float step_y;
  //float	dx;
  //float dy;
  float step;
  int	i;
  
  set_img(&from, &to, img);
  step_x = to.x - from.x;
  step_y = to.y - from.y;
  step = ft_step(step_x, step_y);
  step_x /= step;
  step_y /= step;
  //x = x1;
  //y = y1;
  i = 1;
  while (i <= step) 
  {
    my_mlx_pixel_put(img, from.x, from.y, 0x00FF0000);
    from.x += step_x;
    from.y += step_y;
    i = i + 1;
  }
}

void draw_bites_map(int size_x, int size_y, t_data *img)
{
  int x;
  int y;

  x = 0;
  y = 0;
  //z = matrix[y][x];
  //img.mlx = mlx_init();
	//img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "fdf");
	//img.img = mlx_new_image(img.mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

  while (y < size_y)
  {
    while(x < size_x)
    {
//      my_mlx_pixel_put(img, img->matrix[y][x].x, img->matrix[y][x].y, 0x00FF0000);
      if (x + 1 != size_x)
        draw_line(img, img->matrix[y][x], img->matrix[y][x+1]);
      if (y + 1 != size_y)
        draw_line(img, img->matrix[y][x], img->matrix[y+1][x]);
      x++; 
    }
    x = 0;
    y++;
  }
  mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_hook(img->mlx_win, 17, 0, ft_exit, NULL);
	mlx_key_hook(img->mlx_win, key_hook, NULL);
	mlx_loop(img->mlx);
	mlx_destroy_window(img->mlx, img->mlx_win);
}