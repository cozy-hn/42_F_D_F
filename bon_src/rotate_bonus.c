/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:51:17 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:32:22 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_scale(t_map *map, int flag)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (flag == 1)
			{
				rotate_x(map, i, j);
				rotate_y(map, i, j);
				rotate_z(map, i, j);
			}
			else if (flag == 4)
			{
				map->map[i][j].x *= map->scale;
				map->map[i][j].y *= map->scale;
				map->map[i][j].z *= map->scale;
			}
		}
	}
}

void	rotate_x(t_map *map, int i, int j)
{
	double	y;
	double	z;
	double	coss;
	double	sinn;
	double	angle;

	angle = map->x_angle;
	coss = cos(angle);
	sinn = sin(angle);
	y = map->base_map[i][j].y;
	z = map->base_map[i][j].z;
	map->map[i][j].x = map->base_map[i][j].x;
	map->map[i][j].y = y * coss - z * sinn;
	map->map[i][j].z = y * sinn + z * coss;
}

void	rotate_y(t_map *map, int i, int j)
{
	double	x;
	double	z;
	double	coss;
	double	sinn;
	double	angle;

	angle = map->y_angle;
	coss = cos(angle);
	sinn = sin(angle);
	x = map->map[i][j].x;
	z = map->map[i][j].z;
	map->map[i][j].x = x * coss + z * sinn;
	map->map[i][j].z = -x * sinn + z * coss;
}

void	rotate_z(t_map *map, int i, int j)
{
	double	x;
	double	y;
	double	coss;
	double	sinn;
	double	angle;

	angle = map->z_angle;
	coss = cos(angle);
	sinn = sin(angle);
	x = map->map[i][j].x;
	y = map->map[i][j].y;
	map->map[i][j].x = x * coss - y * sinn;
	map->map[i][j].y = x * sinn + y * coss;
}
