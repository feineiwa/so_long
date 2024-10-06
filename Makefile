NAME = so_long

LIBFT = ./libft/libft.a

PRINTF = ./ft_printf/ft_printf.a

INC = ./include/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I

RM = rm -rf

GETNEXTLINE = get_next_line/get_next_line.a

MINILIBX = minilibx-linux/

LIBRARY = -L$(MINILIBX)/ -lmlx -lX11 -lXext

SRCS = $(wildcard ./srcs/*.c )

all:
	@make -C $(MINILIBX)
	@make -C get_next_line/
	$(CC) $(CFLAGS) $(INC) $(SRCS) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean :
	@make clean -C get_next_line/

fclean : clean
	make clean -C $(MINILIBX)
	make fclean -C get_next_line/
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re