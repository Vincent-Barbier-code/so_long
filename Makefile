SRC1 = main.c windows.c \
	img.c parsing.c \
	map.c \
	free_map.c verif_map.c \
	verif_map_extra.c \
	move_player.c where_player.c

SRC2 = $(PATH_GNL)_utils.c \
	$(PATH_GNL).c

SRC = $(addprefix $(PATH_SRC), $(SRC1)) $(SRC2)
OBJ1 = $(addprefix $(PATH_OBJ), ${SRC1:.c=.o})
OBJ2 = $(addprefix $(PATH_OBJ), ${SRC2:.c=.o})
OBJ = $(OBJ1) $(OBJ2)
NAME = so_long
FLAG = -Wall -Wextra -Werror
DEPS = $(PATH_SRC)so_long.h Makefile

PATH_SRC = ./src/
PATH_OBJ = ./obj/
PATH_GNL = ./get_next_line/get_next_line
FT_PRINTF =  -L ./ft_printf -lftprintf

all : $(NAME)

%.o: %.c
	gcc -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	gcc $(FLAG) $(SRC) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz -g3 -o $(NAME) -lm

$(OBJ) : $(DEPS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re