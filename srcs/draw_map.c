/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:29:00 by abravo            #+#    #+#             */
/*   Updated: 2022/11/25 19:02:09 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
  
  if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
  {
	  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	  *(unsigned int*)dst = color;
  }
}

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

float	ft_abs(int i)
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

void	zoom(t_pts *from, t_pts *to, t_data *data)
{
	from->x *= data->scale;
	from->y *= data->scale;
	to->x *= data->scale;
	to->y *= data->scale;
	from->z *= data->z_scale;
	to->z *= data->z_scale;
  //data->center->x *= data->scale;
  //data->center->y *= data->scale;
}

void	isometric(t_data *data, t_pts *pt)
{
  double  tmp_x;
  
  pt->x -= data->size_x / 2 * data->scale;
  pt->y -= data->size_y / 2 * data->scale;
  tmp_x = pt->x;
	pt->x = (pt->x - pt->y) * cos(data->angle);
	pt->y = (tmp_x + pt->y) * sin(data->angle) - pt->z;
}

void	set_img(t_pts *from, t_pts *to, t_data *data)
{
	zoom(from, to, data);
	isometric(data, from);
	isometric(data, to);
  from->x += data->mid_x;
	from->y += data->mid_y;
	to->y += data->mid_y;
	to->x += data->mid_x;
}

void draw_line(t_data *data, t_pts from, t_pts to)
{
  float step_x;
  float step_y;
  float step;
  int	i;
  
  set_img(&from, &to, data);
  //printf("from x:%f, to x:%f, from y:%f, to y:%f\n", from.x, to.x, from.y, to.y);
  step_x = to.x - from.x;
  step_y = to.y - from.y;
  step = ft_step(step_x, step_y);
  //if (step == 0)
  //  return ;
  step_x /= step;
  step_y /= step;
  i = 1;
  while (i <= step) 
  {
   // printf("testwhile\n");
    my_mlx_pixel_put(data, from.x, from.y, 0x00FF0000);
   // printf("testpixel\n");
    from.x += step_x;
    from.y += step_y;
    i++;
  }
}

void draw_bites_map(t_data *data)
{
  int x;
  int y;

  x = 0;
  y = 0;
  
  while (y < data->size_y)
  {
    while(x < data->size_x)
    {
      // my_mlx_pixel_put(data, x, y, 0xFF0000);
      // my_mlx_pixel_put(data, data->matrix[y][x].x, data->matrix[y][x].y, 0x00FF0000);
      if (x + 1 != data->size_x)
        draw_line(data, data->matrix[y][x], data->matrix[y][x+1]);
      if (y + 1 != data->size_y)
        draw_line(data, data->matrix[y][x], data->matrix[y+1][x]);
      x++;
    }
    x = 0;
    y++;
  }
  mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
  my_mlx_pixel_put(data, 1920 / 2 - 1, 1080 / 2 - 1, 0x00FFFFFF);
  my_mlx_pixel_put(data, 1920 / 2 + 1, 1080 / 2 + 1, 0x00FFFFFF);
  my_mlx_pixel_put(data, 1920 / 2 - 1, 1080 / 2 + 1, 0x00FFFFFF);
  my_mlx_pixel_put(data, 1920 / 2 + 1, 1080 / 2 - 1, 0x00FFFFFF);
  my_mlx_pixel_put(data, 1920 / 2 + 1, 1080 / 2 + 1, 0x00FFFFFF);  
  my_mlx_pixel_put(data, 1920 / 2, 1080 / 2, 0x00FFFFFF);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, NULL);
	mlx_key_hook(data->mlx_win, key_hook, &data);
	mlx_loop(data->mlx);
}