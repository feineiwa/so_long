NAME=a.out

all :$(NAME)

$(NAME):
	cc  -Wall -Werror -Wextra -g *.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c -I ../minilibx-linux/ -L ../minilibx-linux/ -lmlx -lX11 -lXext -o $(NAME)

run: re $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out ../map/faneva.ber

re : 
	rm -rf ./a.out