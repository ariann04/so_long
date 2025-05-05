NAME = so_long

SRC = src/main.c gnl/get_next_line.c gnl/get_next_line_utils.c \
      ft_printf/ft_printf.c ft_printf/ft_handle_chars.c \
      ft_printf/ft_handle_digits.c src/print_map.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -I gnl -I ft_printf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
