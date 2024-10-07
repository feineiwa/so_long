NAME = libftprintf.a

SRCS = \
		ft_print_digits.c ft_print_ptr.c ft_print_str.c ft_printf.c \
		ft_putchar_fd.c ft_putchar.c
OBJS = ${SRCS:.c=.o}

CC = gcc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%o: %.c
		@${CC} ${FLAGS} -c $< -o $@

${NAME} : ${OBJS}
		@${AR} ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
