/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 03:44:50 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:26:07 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ham(t_point p1, t_point p2, int *bham_lst, t_map *map)
{
	bham_lst[0] = round(p1.x);
	bham_lst[1] = round(p1.y);
	bham_lst[2] = round(p2.x);
	bham_lst[3] = round(p2.y);
	bham_lst[4] = abs(bham_lst[2] - bham_lst[0]);
	bham_lst[5] = abs(bham_lst[3] - bham_lst[1]);
	bham_lst[6] = (bham_lst[0] < bham_lst[2]) * 2 - 1;
	bham_lst[7] = (bham_lst[1] < bham_lst[3]) * 2 - 1;
	bham_lst[8] = 0;
	bham_lst[9] = 2 * bham_lst[4];
	bham_lst[10] = 2 * bham_lst[5];
	bham_lst[11] = map->move_x;
	bham_lst[12] = map->move_y;
}

void	dxdy(int *b_lst, t_data *img, int color)
{
	b_lst[8] = b_lst[10] - b_lst[4];
	my_mlx_pixel_put(img, b_lst[0] + b_lst[11], b_lst[1] + b_lst[12], color);
	while (b_lst[0] != b_lst[2])
	{
		b_lst[0] += b_lst[6];
		if (b_lst[8] >= 0)
		{
			b_lst[1] += b_lst[7];
			b_lst[8] -= b_lst[9];
		}
		b_lst[8] += b_lst[10];
		my_mlx_pixel_put(img, b_lst[0] + b_lst[11], \
		b_lst[1] + b_lst[12], color);
	}	
}

void	dydx(int *b_lst, t_data *img, int color)
{
	b_lst[8] = b_lst[9] - b_lst[5];
	my_mlx_pixel_put(img, b_lst[0] + b_lst[11], b_lst[1] + b_lst[12], color);
	while (b_lst[1] != b_lst[3])
	{
		b_lst[1] += b_lst[7];
		if (b_lst[8] >= 0)
		{
			b_lst[0] += b_lst[6];
			b_lst[8] -= b_lst[10];
		}
		b_lst[8] += b_lst[9];
		my_mlx_pixel_put(img, b_lst[0] + b_lst[11], \
		b_lst[1] + b_lst[12], color);
	}
}

void	bresenham(int *b_lst, t_data *img, int color)
{
	if (b_lst[4] >= b_lst[5])
		dxdy(b_lst, img, color);
	else
		dydx(b_lst, img, color);
}
