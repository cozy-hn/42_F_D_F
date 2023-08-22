/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 03:44:50 by jiko              #+#    #+#             */
/*   Updated: 2023/08/23 04:37:17 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*set_bresenham(t_point p1, t_point p2, int *bresenham_list)
{
	bresenham_list[0] = round(p1.x);
	bresenham_list[1] = round(p1.y);
	bresenham_list[2] = round(p2.x);
	bresenham_list[3] = round(p2.y);
	bresenham_list[4] = abs(bresenham_list[2] - bresenham_list[0]);
	bresenham_list[5] = abs(bresenham_list[3] - bresenham_list[1]);
	bresenham_list[6] = (bresenham_list[0] < bresenham_list[2]) * 2 - 1;
	bresenham_list[7] = (bresenham_list[1] < bresenham_list[3]) * 2 - 1;
	bresenham_list[8] = 0;
	bresenham_list[9] = 2 * bresenham_list[4];
	bresenham_list[10] = 2 * bresenham_list[5];
	return (bresenham_list);
}

void	dxdy(int *b_list, t_data *img)
{
	b_list[8] = b_list[10] - b_list[4];
	my_mlx_pixel_put(img, b_list[0], b_list[1], 0xFFFFFF);
	while (b_list[0] != b_list[2])
	{
		b_list[0] += b_list[6];
		if (b_list[8] >= 0)
		{
			b_list[1] += b_list[7];
			b_list[8] -= b_list[9];
		}
		b_list[8] += b_list[10];
		my_mlx_pixel_put(img, b_list[0], b_list[1], 0xFFFFFF);
	}	
}

void	dydx(int *b_list, t_data *img)
{
	b_list[8] = b_list[9] - b_list[5];
	my_mlx_pixel_put(img, b_list[0], b_list[1], 0xFFFFFF);
	while (b_list[1] != b_list[3])
	{
		b_list[1] += b_list[7];
		if (b_list[8] >= 0)
		{
			b_list[0] += b_list[6];
			b_list[8] -= b_list[10];
		}
		b_list[8] += b_list[9];
		my_mlx_pixel_put(img, b_list[0], b_list[1], 0xFFFFFF);
	}
}

void	bresenham(int *b_list, t_data *img)
{
	if (b_list[4] >= b_list[5])
		dxdy(b_list, img);
	else
		dydx(b_list, img);
}
