# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# CLIB = -L ./minilibx_mms_20210621 -lmlx -framework OpenGL -framework Appkit -lz

# RMF = rm -f
# SRC = main.c get_next_line.c get_next_line_utils.c ctl_color.c

# OBJT = $(SRC:.c=.o)
# # BONUS = 
# BOBJT = $(BONUS:.c=.o)
# NAME = fdf.out

# all: $(NAME)

# bonus: $(BOBJT) $(NAME)
# 	$(AR) $(NAME) $(BOBJT)
# 	@touch bonus

# $(NAME): $(OBJT)
# 	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	$(RMF) $(OBJT) $(BOBJT) bonus

# fclean: clean
# 	$(RMF) $(NAME)

# re: fclean
# 	make

# .PHONY : all clean fclean re


CC = gcc
FLAGS = -L ./minilibx_mms_20210621 -lmlx -framework OpenGL -framework Appkit -lz
CFLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line.c get_next_line_utils.c ctl_color.c
NAME = FDF
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