NAME = so_long
FLAG = -Wall -Wextra -Werror
DEPS = $(PATH_SRC)so_long.h Makefile
PATH_SRC = src/
PATH_OBJ = obj/
PATH_GNL = get_next_line/
FT_PRINTF =  -L ./ft_printf -lftprintf

SRC_FILES = $(addprefix $(PATH_SRC), main.c windows.c \
	img.c parsing.c \
	map.c \
	free_map.c verif_map.c \
	verif_map_extra.c \
	move_player.c where_player.c \
	get_next_line_utils.c \
	get_next_line.c)

#SRC = $(addprefix $(PATH_SRC), $(SRC_FILES))
OBJ = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC_FILES))

$(PATH_OBJ)%.o: $(SRC_PATH)%.c
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	gcc $(FLAG) -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(DEPS)
	$(make) -C ft_printf/
	gcc $(FLAG) $(OBJ) $(FT_PRINTF) -L minilibx-linux -Imlx_linux -lXext -lX11 -lz -g3 -o $(NAME) -lm

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re