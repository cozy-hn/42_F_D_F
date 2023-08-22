/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:39:59 by jiko              #+#    #+#             */
/*   Updated: 2023/08/23 04:40:02 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	int		bresenham_list[11];

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, Window_Max_X, Window_Max_Y, "FDF");
	img.img = mlx_new_image(vars.mlx, Window_Max_X, Window_Max_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 20, 20, create_trgb(0, 255, 255, 255));
	set_bresenham((t_point){50, 50, 0, 0}, (t_point){500, 500, 0, 0}, bresenham_list);
	bresenham(bresenham_list, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, KeyPress, 0, mlx_close, &vars);
	mlx_hook(vars.win, Click_X, 0, click_x, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
