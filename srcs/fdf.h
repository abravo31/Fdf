/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:21:55 by abravo            #+#    #+#             */
/*   Updated: 2022/10/28 19:44:32 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_data
{
    void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int endian;
    int prev_x;
    int prev_y;
}	t_data;

#endif