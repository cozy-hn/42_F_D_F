/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:25:11 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:53:22 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "get_next_line_bonus.h"
# include "../minilibx_mms_20210621/mlx.h"
# include <math.h>

# define WIN_MAX_X 1920
# define WIN_MAX_Y 1080

typedef struct s_point {
	double	x;
	double	y;
	double	z;
	int		c;
}	t_point;

typedef struct s_map {
	int		height;
	int		width;
	double	scale;
	double	init_scale;
	int		move_x;
	int		move_y;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	double	max_x;
	double	max_y;
	double	min_x;
	double	min_y;
	t_point	**base_map;
	t_point	**map;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	long	bonus;
	t_map	map;
}	t_data;

enum e_Keys {
	UP = 126,
	DOWN = 125,
	LEFT = 123,
	RIGHT = 124,
	ESC = 53,
	KeyPress = 2,
	KeyRelease = 3,
	Click_X = 17,
	ZOOM_IN = 0,
	ZOOM_OUT = 1,
	ROTATE_X = 12,
	REV_ROTATE_X = 13,
	ROTATE_Y = 14,
	REV_ROTATE_Y = 15,
	ROTATE_Z = 2,
	REV_ROTATE_Z = 3,
	RESET = 5,
};

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fdf_init(char *argv, t_data *data);
int		vaild_file_name(char *path);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	open_map(t_map *map, char *path);
int		set_height_width(t_map *map, int fd);
void	check_word_set_i(const char *str, char c, int *num_word, int *i);
int		malloc_map(t_map *map);
int		set_map(t_map *map, int fd);
int		ft_atoi(char *str);
void	set_point(t_map *map, int x, int y, char **split);
char	**ft_split(char const *str, char c);
int		is_deli(char c, char c2);
void	set_size_word(const char *str, char c, int *size_word);
char	**dobi_free(int i, char	**be_return);
void	init_sclaed_map(t_map *map);
void	init_angle_scale(t_map *map);
void	rotate_scale(t_map *map, int flag);
void	rotate_x(t_map *map, int i, int j);
void	rotate_y(t_map *map, int i, int j);
void	rotate_z(t_map *map, int i, int j);
void	set_scaled_map(t_map *map);
void	draw_img(t_data *img);
void	ham(t_point p1, t_point p2, int *bresenham_list, t_map *map);
void	bresenham(int *b_list, t_data *img, int color);
void	dxdy(int *b_list, t_data *img, int color);
void	dydx(int *b_list, t_data *img, int color);
void	set_maxmin(t_map *map);
int		hex_to_dex(char *hex);
void	move_ctl(int keycode, t_data *data);
void	rotate_ctl(int keycode, t_data *data);
int		click_x(t_data *vars);
int		mlx_keyctl(int keycode, t_data *vars);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif