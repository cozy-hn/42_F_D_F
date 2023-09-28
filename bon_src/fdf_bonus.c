/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:14:03 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:55:31 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_MAX_X || y < 0 || y >= WIN_MAX_Y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fdf_init(char *argv, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_MAX_X, WIN_MAX_Y, argv);
	data->img = mlx_new_image(data->mlx, WIN_MAX_X, WIN_MAX_Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	open_map(&data->map, argv);
	if (data->map.width > 1 || data->map.height > 1)
	{
		init_sclaed_map(&data->map);
		draw_img(data);
	}
	else
	{
		data->map.move_x = WIN_MAX_X / 2;
		data->map.move_y = WIN_MAX_Y / 2;
		my_mlx_pixel_put(data, data->map.move_x, data->map.move_y, \
		data->map.base_map[0][0].c);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !vaild_file_name(argv[1]))
		exit(1);
	fdf_init(argv[1], &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, KeyPress, 0, mlx_keyctl, &data);
	mlx_hook(data.win, Click_X, 0, click_x, &data);
	mlx_loop(data.mlx);
	exit (0);
}
