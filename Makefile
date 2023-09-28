CC = gcc
FLAGS = -L ./minilibx_mms_20210621 -lmlx -framework OpenGL -framework Appkit -lz
CFLAGS = -Wall -Wextra -Werror
SRC_NAME = fdf get_next_line get_next_line_utils color_ctl key_ctl file_ctl file_ctl_2 fdf_libft \
ft_split bresenham draw rotate
RMF = rm -f

MAN_DIR = ./man_src/
MAN_SRC = $(addprefix $(MAN_DIR), $(addsuffix .c, $(SRC_NAME)))
MAN_OBJ = $(addprefix $(MAN_DIR), $(addsuffix .o, $(SRC_NAME)))
NAME = ./fdf

BON_DIR = ./bon_src/
BON_SRC = $(addprefix $(BON_DIR), $(addsuffix _bonus.c, $(SRC_NAME)))
BON_OBJ = $(addprefix $(BON_DIR), $(addsuffix _bonus.o, $(SRC_NAME)))
BON_NAME = ./fdf_bonus

all : $(NAME)

$(NAME) : $(MAN_OBJ)
	$(CC) $(CFLAGS) $(FLAGS) $^ -o $@

bonus : $(BON_OBJ)
	$(CC) $(CFLAGS) $(FLAGS) $^ -o $(BON_NAME)
	@touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -I $(dir $<) -c $< -o $@

clean :
	$(RMF) $(MAN_OBJ) $(BON_OBJ) bonus

fclean : clean
	$(RMF) $(NAME) $(BON_NAME)

re: fclean
	make

.PHONY : all clean fclean re