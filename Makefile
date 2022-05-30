SRC = test.c windows.c img.c parsing.c
OBJ = ${SRC:.c=.o}
NAME = so_long
FLAG = -Wall -Wextra -Werror #-g -fsanitize=address -g3
DEPS = so_long.h Makefile
all : $(NAME)

%.o: %.c
	gcc -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz -g3 -o $(NAME) -lm

$(OBJ) : $(DEPS)

.PHONY : all