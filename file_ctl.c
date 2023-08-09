/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:58:30 by jiko              #+#    #+#             */
/*   Updated: 2023/08/09 22:19:38 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	vaild_file_name(char *path)
{
	if (ft_strlen(path) < 4)
		return (0);
	if (ft_strncmp(path + ft_strlen(path) - 4, ".fdf", 5))
		return (0);
	return (1);
}

int	set_height_width(t_map *map, int fd)
{
	int		tmp;
	char	*line;

	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	check_word_set_i(line, ' ', &map->width, NULL);
	while (1)
	{
		check_word_set_i(line, ' ', &tmp, NULL);
		if (tmp != map->width)
			return (0);
		map->height++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (1);
}

int	malloc_map(t_map *map)
{
	int	idx;

	idx = 0;
	map->map = (t_point **)malloc(sizeof(t_point *) * map->height + 1);
	map->map[map->height] = NULL;
	while (idx < map->height)
		map->map[idx++] = (t_point *)malloc(sizeof(t_point) * map->width);
	idx = 0;
	return (1);
}

int	set_map(t_map *map, int fd)
{
	int		idx;
	int		idx2;
	char	*line;
	char	**split;

	idx = 0;
	while (idx < map->height)
	{
		idx2 = 0;
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		free(line);
		while (idx2 < map->width)
		{
			map->map[idx][idx2].x = idx2;
			map->map[idx][idx2].y = idx;
			map->map[idx][idx2].z = ft_atoi(split[idx2]);
			line = ft_strchr(split[idx2], ',');
			if (line)
				map->map[idx][idx2].c = ft_atoi_base(line + 3, 16);
			else
				map->map[idx][idx2].c = 0xFFFFFF;
			idx2++;
		}
		dobi_free(idx2, split);
		idx++;
	}
	return (1);
}

void	open_map(t_map *map, char *path)
{
	int		fd;

	if (!vaild_file_name(path))
		exit(1);
	fd = open(path, O_RDONLY);
	if (!set_height_width(map, fd))
		exit(1);
	close(fd);
	fd = open(path, O_RDONLY);
	malloc_map(map);
	set_map(map, fd);
	close(fd);
}
