/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 06:00:16 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:31:06 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_maxmin(t_map *map)
{
	int	i;
	int	j;

	map->max_x = map->map[0][0].x;
	map->max_y = map->map[0][0].y;
	map->min_x = map->map[0][0].x;
	map->min_y = map->map[0][0].y;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->max_x = fmax(map->max_x, map->map[i][j].x);
			map->max_y = fmax(map->max_y, map->map[i][j].y);
			map->min_x = fmin(map->min_x, map->map[i][j].x);
			map->min_y = fmin(map->min_y, map->map[i][j].y);
		}
	}
}

void	init_angle_scale(t_map *map)
{
	map->x_angle = 35.264 * (M_PI / 180);
	map->y_angle = 45 * (M_PI / 180);
	map->z_angle = -35.264 * (M_PI / 180);
}

void	init_sclaed_map(t_map *map)
{
	init_angle_scale(map);
	rotate_scale(map, 1);
	set_scaled_map(map);
	rotate_scale(map, 4);
}

void	set_scaled_map(t_map *map)
{
	double	x;
	double	y;

	set_maxmin(map);
	x = map->max_x - map->min_x;
	y = map->max_y - map->min_y;
	map->init_scale = WIN_MAX_X / (fmax(x, y) + 0.001) / 2;
	map->move_x = (WIN_MAX_X - (map->max_x + map->min_x) * map->init_scale) / 2;
	map->move_y = (WIN_MAX_Y - (map->max_y + map->min_y) * map->init_scale) / 2;
	map->scale = map->init_scale;
}

void	draw_img(t_data *img)
{
	int		b_lst[13];
	int		i;
	int		j;

	i = -1;
	while (++i < img->map.height)
	{
		j = -1;
		while (++j < img->map.width - 1)
		{
			ham(img->map.map[i][j], img->map.map[i][j + 1], b_lst, &img->map);
			bresenham(b_lst, img, img->map.base_map[i][j].c);
		}
	}
	i = -1;
	while (++i < img->map.height - 1)
	{
		j = -1;
		while (++j < img->map.width)
		{
			ham(img->map.map[i][j], img->map.map[i + 1][j], b_lst, &img->map);
			bresenham(b_lst, img, img->map.base_map[i][j].c);
		}
	}
}
