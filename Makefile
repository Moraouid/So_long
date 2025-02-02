NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c src/map_parser.c
OBJ = $(SRC:.c=.o)
MLX = -I/usr/include/minilibx-linux -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft/libft.a

GNL_SRC = libft/get_next_line/get_next_line.c libft/get_next_line/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(MLX) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)/libft

clean:
	$(MAKE) -C $(LIBFT_DIR)/libft clean
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR)/libft fclean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)_bonus