/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ctl_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:02:52 by jiko              #+#    #+#             */
/*   Updated: 2023/08/24 05:53:22 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_point(t_map *map, int x, int y, char **split)
{
	char	*line;

	map->map[y][x].x = x * 30;
	map->map[y][x].y = y * 30;
	map->map[y][x].z = ft_atoi(split[x]) * 30;
	line = ft_strchr(split[x], ',');
	if (line)
		map->map[y][x].c = hex_to_dex(line + 3);
	else
		map->map[y][x].c = 0xFFFFFF;
}


// #include <stdio.h>

// int main(int argc, char **argv) //test for open_map
// {
// 	t_map	map;

// 	open_map(&map, argv[1]);
// 	printf("height: %d\n", map.height);
// 	printf("width: %d\n", map.width);
// 	for (int i = 0; i < map.height; i++)
// 	{
// 		for (int j = 0; j < map.width; j++)
// 			printf("x: %f, y: %f, z: %f, c: %d\n", map.map[i][j].x, map.map[i][j].y, map.map[i][j].z, map.map[i][j].c);
// 		printf("\n");
// 	}
// 	return (0);
// }
	