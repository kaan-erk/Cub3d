NAME = cub3d

CC = cc -g
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I./includes

LIBFT = libft/libft.a

PARSING =	parse/parse.c \
			parse/map_checker.c \
			parse/map_texture.c \
			parse/floor_ceiling.c \
			parse/parse_error.c

SRC = 	src/get_next_line.c \
		src/get_next_line_utils.c

EXECUTE = \
	

SRCS = $(PARSING) \
	   $(EXECUTE) \
	   $(SRC) \
	   main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft -s
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
