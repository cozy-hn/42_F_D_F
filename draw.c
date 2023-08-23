/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 06:00:16 by jiko              #+#    #+#             */
/*   Updated: 2023/08/24 06:44:17 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_img(t_map *map, t_data *img)
{
	int		bresenham_list[11];
	t_point	p1;
	t_point	p2;

	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width - 1; j++)
		{
			p1 = map->map[i][j];
			p2 = map->map[i][j + 1];
			set_bresenham(p1, p2, bresenham_list, map);
			bresenham(bresenham_list, img);
		}
	}
	for (int i = 0; i < map->width; i++)
	{
		for (int j = 0; j < map->height - 1; j++)
		{
			p1 = map->map[j][i];
			p2 = map->map[j + 1][i];
			set_bresenham(p1, p2, bresenham_list, map);
			bresenham(bresenham_list, img);
		}
	}
}
