# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:01:15 by ftudini           #+#    #+#              #
#    Updated: 2021/10/11 18:07:25 by ftudini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ./src/ft_hex \
	./src/ft_int \
	./src/ft_percent \
	./src/ft_printf \
	./src/ft_ptr \
	./src/ft_str \
	./src/ft_unsigned \
	./src/ft_itoa \
	./src/ft_putchar_fd \
	./src/ft_strdup \
	./src/ft_strlen \

SRCS = $(addsuffix .c, $(SRC))

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