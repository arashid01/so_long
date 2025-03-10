NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_uint.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar
ARFLAGS = rcs

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
