/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctl_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:38:50 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:55:46 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	click_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	move_ctl(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == UP)
		data->map.move_y -= 15;
	else if (keycode == DOWN)
		data->map.move_y += 15;
	else if (keycode == LEFT)
		data->map.move_x -= 15;
	else if (keycode == RIGHT)
		data->map.move_x += 15;
	else if (keycode == ZOOM_IN)
	{
		data->map.scale *= 1.2;
		if (data->map.scale > 10000)
			data->map.scale = 10000;
	}
	else if (keycode == ZOOM_OUT)
	{
		data->map.scale *= 0.8;
		if (data->map.scale < 0.1)
			data->map.scale = 0.1;
	}
}

void	rotate_ctl(int keycode, t_data *data)
{
	if (keycode == ROTATE_X)
		data->map.x_angle += 0.05;
	else if (keycode == REV_ROTATE_X)
		data->map.x_angle -= 0.05;
	else if (keycode == ROTATE_Y)
		data->map.y_angle += 0.05;
	else if (keycode == REV_ROTATE_Y)
		data->map.y_angle -= 0.05;
	else if (keycode == ROTATE_Z)
		data->map.z_angle += 0.05;
	else if (keycode == REV_ROTATE_Z)
		data->map.z_angle -= 0.05;
	else if (keycode == RESET)
	{
		if (data->map.width > 1 || data->map.height > 1)
			init_sclaed_map(&data->map);
		else
		{
			data->map.move_x = WIN_MAX_X / 2;
			data->map.move_y = WIN_MAX_Y / 2;
		}
	}
}

void	bonus_ctl(int keycode, t_data *data)
{
	data->bonus = 0;
	data->map.y_angle = 0;
	data->map.z_angle = 0;
	data->map.x_angle = 0;
	if (keycode == 31)
		data->map.x_angle = 90 * M_PI / 180;
	else if (keycode == 35)
		data->map.y_angle = 90 * M_PI / 180;
	else if (keycode == 33)
	{
		while (++(data->bonus) < 100)
		{
			data->map.z_angle += 0.05;
			data->map.z_angle = fmod(data->map.z_angle, 2 * M_PI);
			usleep(50000);
			mlx_destroy_image(data->mlx, data->img);
			data->img = mlx_new_image(data->mlx, WIN_MAX_X, WIN_MAX_Y);
			data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
			rotate_scale(&data->map, 1);
			rotate_scale(&data->map, 4);
			draw_img(data);
			mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		}
	}
}

int	mlx_keyctl(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT \
	|| keycode == ZOOM_IN || keycode == ZOOM_OUT || keycode == ESC)
		move_ctl(keycode, data);
	else if (keycode == 31 || keycode == 35 || keycode == 33)
		bonus_ctl(keycode, data);
	else if (keycode == REV_ROTATE_X || keycode == ROTATE_X || keycode == \
	REV_ROTATE_Y || keycode == ROTATE_Y || keycode == REV_ROTATE_Z || \
	keycode == ROTATE_Z || keycode == RESET)
		rotate_ctl(keycode, data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_MAX_X, WIN_MAX_Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	rotate_scale(&data->map, 1);
	rotate_scale(&data->map, 4);
	if (data->map.width > 1 || data->map.height > 1)
		draw_img(data);
	else
		my_mlx_pixel_put(data, data->map.move_x, data->map.move_y, \
		data->map.base_map[0][0].c);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
