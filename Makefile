SRC = test.c windows.c img.c parsing.c basique.c map.c verif_map.c\
	$(PATH_GNL)get_next_line_utils.c \
	$(PATH_GNL)get_next_line.c
OBJ = ${SRC:.c=.o}
NAME = so_long
FLAG = -Wall -Wextra -Werror #-g -fsanitize=address -g3
DEPS = so_long.h Makefile
PATH_GNL = ./get_next_line/
all : $(NAME)

%.o: %.c
	gcc -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz -g3 -o $(NAME) -lm

$(OBJ) : $(DEPS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re