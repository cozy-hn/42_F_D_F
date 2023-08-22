CC = gcc
FLAGS = -L ./minilibx_mms_20210621 -lmlx -framework OpenGL -framework Appkit -lz
CFLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line.c get_next_line_utils.c color_ctl.c key_ctl.c file_ctl.c file_ctl_2.c fdf_libft.c \
ft_split.c fdf_libft_2.c bresenham.c draw.c
NAME = fdf
OBJECTS = $(SRC:.c=.o)
INC = -I./
RMF = rm -f

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o : %.c
	$(CC) -c $(INC) $<

clean :
	$(RMF) $(OBJECTS) $(OBJECTS2) bonus

fclean : clean
	$(RMF) $(NAME)

re: fclean
	make

.PHONY : all clean fclean re