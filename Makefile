# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 20:24:11 by aestrell          #+#    #+#              #
#    Updated: 2024/03/11 20:24:11 by aestrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
LIBFT=libft/libft.a
SRCS = $(wildcard *.c)
OBJS=$(SRCS:.c=.o)


CC=gcc
CFLAGS=-Wall -Wextra -Werror -g


all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus