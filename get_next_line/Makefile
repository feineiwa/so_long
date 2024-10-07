NAME = get_next_line.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

OBJ_DIR = objs

RM = rm -rf

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
		@ar -rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@

clean :
		@$(RM) $(OBJ_DIR)

fclean : clean
		@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
 