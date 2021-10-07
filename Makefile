
NAME	=	libftprintf.a

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

AR	=	ar
ARFLAGS	=	rcs

SRCS	=		./srcs/ft_calloc.c \
				./srcs/ft_convert.c \
				./srcs/ft_itoa.c \
				./srcs/ft_printf.c \
				./srcs/ft_putchar_fd.c \
				./srcs/ft_putnbr_base.c \
				./srcs/ft_putnbr_fd.c \
				./srcs/ft_putstr_fd.c \
				./srcs/ft_strlen.c \

OBJS = ${SRCS:.c=.o}

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all