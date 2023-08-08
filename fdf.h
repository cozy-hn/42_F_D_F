/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:25:11 by jiko              #+#    #+#             */
/*   Updated: 2023/08/08 23:06:46 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "./minilibx_mms_20210621/mlx.h"
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map {
	int	height;
	int	width;
}	t_map;

enum e_Keys {
	UP = 126,
	DOWN = 125,
	LEFT = 123,
	RIGHT = 124,
	ESC = 53,
	KeyPress = 2,
	KeyRelease = 3,
	Click_X = 17,
	Window_Max_X = 1980,
	Window_Max_Y = 1080
};

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mlx_close(int keycode, t_vars *vars);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		vaild_file_name(char *path);
int		click_x(t_vars *vars);
int		is_deli(char c, char c2);
void	check_word_set_i(const char *str, char c, int *num_word, int *i);
void	set_size_word(const char *str, char c, int *size_word);
char	**dobi_free(int i, char	**be_return);
char	**ft_split(char const *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif