/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ctl_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:02:52 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:31:55 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_point(t_map *map, int x, int y, char **split)
{
	char	*line;

	map->base_map[y][x].x = x - map->width / 2;
	map->base_map[y][x].y = y - map->height / 2;
	map->base_map[y][x].z = (double)ft_atoi(split[x]) / 3;
	line = ft_strchr(split[x], ',');
	if (line)
		map->base_map[y][x].c = hex_to_dex(line + 3);
	else
		map->base_map[y][x].c = 0xFFFFFF;
}
