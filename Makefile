NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c src/map_parser.c
OBJ = $(SRC:.c=.o)
MLX = -I/usr/include/minilibx-linux -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)_bonus