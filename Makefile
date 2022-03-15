# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/03/14 19:10:03 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS =		create_list.c		\
			check_input_data.c	\
			push_swap.c			\
			list_utils.c		\
			swap_op.c			\
			push_op.c			\
			rotate_op.c			\
			reverse_rotate_op.c	\
			id_utils.c			\
			ps_sort.c			\
			triple_sort.c		\
			r_count_utils.c		\
			rr_count_utils.c

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
RM = rm -f

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

