SRC = main.c windows.c \
	img.c parsing.c \
	map.c \
	free_map.c verif_map.c \
	verif_map_extra.c \
	move_player.c where_player.c \
	$(PATH_GNL)_utils.c \
	$(PATH_GNL).c
OBJ = ${SRC:.c=.o}
NAME = so_long
FLAG = -Wall -Wextra -Werror
DEPS = so_long.h Makefile

PATH_GNL = ./get_next_line/get_next_line
FT_PRINTF =  -L ./ft_printf -lftprintf
all : $(NAME)

%.o: %.c
	gcc -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz -g3 -o $(NAME) -lm

$(OBJ) : $(DEPS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re