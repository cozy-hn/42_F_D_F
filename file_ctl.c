/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:58:30 by jiko              #+#    #+#             */
/*   Updated: 2023/08/19 01:31:08 by jiko             ###   ########.fr       */
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
		idx2 = -1;
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		free(line);
		while (++idx2 < map->width)
			set_point(map, idx2, idx, split);
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
	printf("test\n");
	fd = open(path, O_RDONLY);
	if (!set_height_width(map, fd))
		exit(1);
	close(fd);
	fd = open(path, O_RDONLY);
	malloc_map(map);
	set_map(map, fd);
	close(fd);
}
