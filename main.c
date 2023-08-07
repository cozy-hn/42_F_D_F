/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:39:59 by jiko              #+#    #+#             */
/*   Updated: 2023/08/07 22:41:40 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_mms_20210621/mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 1200, "FDF");
	img.img = mlx_new_image(mlx, 2000, 1200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, create_trgb(0, 255, 255, 255));
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
