/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:29:00 by abravo            #+#    #+#             */
/*   Updated: 2022/11/25 19:27:23 by abravo           ###   ########.fr       */
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

void	zoom(t_pts *pt, t_data *data)
{
	pt->x *= data->scale;
	pt->y *= data->scale;
	pt->z *= data->z_scale;
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

void	set_img(t_data *data)
{
  int y;
  int x;
  
  y = -1;
  while (++y < data->size_y)
  {
    x = -1;
    while (++x < data->size_x)
    {
      zoom(&data->matrix[y][x], data);
    	isometric(data, &data->matrix[y][x]);
      data->matrix[y][x].x += data->mid_x;
    	data->matrix[y][x].y += data->mid_y;
    }
  }

}

void draw_line(t_data *data, t_pts from, t_pts to)
{
  float step_x;
  float step_y;
  float step;
  int	i;
  
  step_x = to.x - from.x;
  step_y = to.y - from.y;
  step = ft_step(step_x, step_y);
  step_x /= step;
  step_y /= step;
  i = 1;
  while (i <= step) 
  {
    my_mlx_pixel_put(data, from.x, from.y, 0x00FF0000);
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

  mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->addr = mlx_get_data_addr(data->img,
      &(data->bits_per_pixel), &(data->line_length), &(data->endian));
  set_img(data);
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
  // my_mlx_pixel_put(data, 1920 / 2 - 1, 1080 / 2 - 1, 0x00FFFFFF);
  // my_mlx_pixel_put(data, 1920 / 2 + 1, 1080 / 2 + 1, 0x00FFFFFF);
  // my_mlx_pixel_put(data, 1920 / 2 - 1, 1080 / 2 + 1, 0x00FFFFFF);
  // my_mlx_pixel_put(data, 1920 / 2 + 1, 1080 / 2 - 1, 0x00FFFFFF);
  // my_mlx_pixel_put(data, 1920 / 2 + 1, 1080 / 2 + 1, 0x00FFFFFF);  
  // my_mlx_pixel_put(data, 1920 / 2, 1080 / 2, 0x00FFFFFF);
}