NAME = cub3D

CC = cc -g
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I./includes -I/usr/local/include -I/usr/X11/include

LIBFT = libft/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LDFLAGS = -L/usr/X11/lib -lXext -lX11 -lm

PARSING =  parse/parse.c \
			parse/map_checker.c \
			parse/map_texture.c \
			parse/floor_ceiling.c \
			parse/parse_error.c \
			parse/map.c

SRC = src/get_next_line.c \
		src/get_next_line_utils.c \
		src/free.c \
		src/free_func.c

EXECUTE = execute/player_information.c \
			execute/start_mlx.c \
			execute/raycasting.c \
			execute/movement.c \
			execute/rotate.c \
			execute/loop_mlx.c \
			execute/ray_func.c
			

SRCS = $(PARSING) \
		$(EXECUTE) \
		$(SRC) \
		main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS)

$(LIBFT):
	@make -C libft -s

$(MLX):
	@make -C $(MLX_DIR) -s

clean:
	@make clean -C libft -s
	@make clean -C $(MLX_DIR) -s
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft -s

	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re