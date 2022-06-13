NAME = so_long
CFLAGS = -Wall -Wextra -Werror
DEPS = $(SRC_DIR)so_long.h Makefile
SRC_DIR = src/
OBJ_DIR = obj/
GN_DIR = get_next_line/
FT_PRINTF =  -L ./ft_printf -lftprintf

SRC_FILES = $(addprefix $(SRC_DIR), main.c windows.c \
	img.c parsing.c \
	map.c \
	free_map.c verif_map.c \
	verif_map_extra.c \
	move_player.c where_player.c \
	get_next_line_utils.c \
	get_next_line.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	gcc $(CFLAGS) -Imlx_linux -c $< -o $@

$(NAME): $(OBJ) $(DEPS)
	$(MAKE) -C minilibx-linux/
	$(MAKE) -C ft_printf/
	gcc $(CFLAGS) $(OBJ) $(FT_PRINTF) -L minilibx-linux ./minilibx-linux/libmlx.a -Imlx_linux -lXext -lX11 -lz -g3 -o $(NAME) -lm

all : $(NAME)

clean :
	$(MAKE) clean -C ft_printf/
	$(MAKE) clean -C minilibx-linux/
	rm -f $(OBJ)

fclean : clean
	$(MAKE) fclean -C ft_printf/
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re