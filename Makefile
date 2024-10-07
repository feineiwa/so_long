NAME = so_long

LIBFT = ./libft/libft.a

PRINTF = ./ft_printf/libftprintf.a

INC = ./include/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I

RM = rm -rf

GETNEXTLINE = get_next_line/get_next_line.a

MINILIBX = minilibx-linux/

LIBRARY = -L$(MINILIBX) -lmlx -lX11 -lXext

SRC_DIR = srcs/

OBJ_DIR = obj/

SRCS = all_error.c control_keys.c ft_check_map_first.c ft_check_map_second.c \
		game_building.c get_map.c main.c move_player.c so_long_utils.c direction_function.c\

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))


all: $(NAME)

$(NAME) : $(OBJS)
		@make -C $(MINILIBX)
		@make -C get_next_line/
		@make -C ft_printf/
		@make -C libft/
		$(CC) $(CFLAGS) $(INC) $(OBJS) $(GETNEXTLINE) $(LIBFT) $(PRINTF) $(LIBRARY) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
		@make clean -C get_next_line/
		@make clean -C ft_printf/
		@make clean -C libft/
		@$(RM) $(OBJ_DIR)

fclean : clean
		make clean -C $(MINILIBX)
		make fclean -C get_next_line/
		make fclean -C ft_printf/
		make fclean -C libft/
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re