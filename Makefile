# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/03/26 20:23:31 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = includes/

INCLUDES = $(INCLUDES_PATH)push_swap.h

RM = @rm -f

SOURCES_DIR = sources/

SRCS_FILES =	create_list.c		\
				check_input_data.c	\
				list_utils.c		\
				struct_utils.c		\
				swap_op.c			\
				push_op.c			\
				rotate_op.c			\
				reverse_rotate_op.c	\
				id_utils.c			\
				pre_sort_utils.c	\
				fill_stack_b.c		\
				cost_utils.c		\
				insertion_utils.c	\
				insertion_utils_2.c	\
				deallocate_utils.c	\
				print_utils.c		\
				push_swap.c

SRCS = $(addprefix $(SOURCES_DIR), $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all :lib $(NAME)

%.o: %.c $(INCLUDES) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

lib :
	make -C libft

$(NAME) : $(INCLUDES) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C libft
	@echo "clean done"

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)
	make fclean -C libft
	@echo "fclean done"

re :	fclean all
