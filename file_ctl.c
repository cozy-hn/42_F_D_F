/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:58:30 by jiko              #+#    #+#             */
/*   Updated: 2023/08/08 23:19:09 by jiko             ###   ########.fr       */
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

void	open_map(t_map *map, char *path)
{
	int		fd;
	int		tmp;
	char	*line;

	if (!vaild_file_name(path))
		exit(1);
	map->height = 0;
	map->width = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	check_word_set_i(line, ' ', &map->width, 0);

}
