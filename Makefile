NAME = so_long

SRC = src/so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src/map_manipulation.c src/map_validation.c src/game.c src/map_validation2.c src/free.c src/moves.c src/dfs.c src/utils.c
OBJ := $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -Ilibft -Ift_printf
MLX = -lmlx -lXext -lX11 -lm

.PHONY: all clean fclean re libft ft_printf

all : libft ft_printf $(NAME)

libft:
	@make -C libft

ft_printf:
	@make -C ft_printf

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(MLX) -Llibft -lft -Lft_printf -lftprintf -L./MinilibX

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf

re: fclean all
