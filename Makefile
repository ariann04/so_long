NAME = so_long

MLX42_DIR = MLX42
MLX42_INC = -I$(MLX42_DIR)/include
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -lGL -lm -lX11 -lpthread -lXrandr -lXinerama -lXcursor -lXext

SRC = src/main_mlx.c gnl/get_next_line.c gnl/get_next_line_utils.c \
      ft_printf/ft_printf.c ft_printf/ft_handle_chars.c ft_printf/ft_handle_digits.c src/print_map.c \
      src/check_map.c src/cleaner.c src/flood_fill.c src/movements.c src/render_map.c src/init_game.c \
      $(wildcard libft/*.c)
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -I gnl -I ft_printf -I libft $(MLX42_INC)

$(NAME): $(OBJ) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX42_LIB) $(MLX42_FLAGS)

$(MLX42_LIB):
	cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
	cmake --build $(MLX42_DIR)/builid

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
