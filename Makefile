# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/02/04 16:59:35 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SERVER = server
# CLIENT = client
NAME = push_swap
SRCS =		create_list.c		\
			check_input_data.c	\
			push_swap.c

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
RM = rm -f

# $(NAME):	lib server

all:	lib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	make -C libft

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# $(NAME):	$(OBJS) $(LIBFT)
# 			$(CC) $(CFLAGS) $? -o $@

clean:
		$(RM) $(OBJS)
		make clean -C libft

fclean:	clean
		$(RM) $(NAME)
		make fclean -C libft

re:	fclean all

.PHONY:	all clean fclean re

