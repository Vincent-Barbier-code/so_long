SRC = test.c
OBJ = ${SRC:.c=.o}
NAME = so_long

all : $(NAME)

%.o: %.c
	gcc -Imlx_linux -O3 -c $< -o $@
	

$(NAME): $(OBJ)
	gcc $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz -g3 -o $(NAME) -lm 
.PHONY : all