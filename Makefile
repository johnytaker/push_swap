# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/04/03 05:22:17 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = ./includes/

INCLUDES = $(INCLUDES_PATH)push_swap.h

RM = @rm -rf

SRCS_DIR = ./sources/

SRCS_FILES = 	create_list_and_fill_b.c	check_input_data.c	\
				list_utils.c				struct_utils.c		\
				swap_op.c					push_op.c			\
				rotate_op.c					reverse_rotate_op.c	\
				id_utils.c					small_sort_utils.c	\
				cost_utils.c				insertion_utils.c	\
				parse_and_sort.c			insertion_utils_2.c	\
				deallocate_utils.c			print_utils.c		\
				push_swap.c

SRCS_FILES_B = 	create_list_and_fill_b.c	check_input_data.c	\
				list_utils.c				struct_utils.c		\
				swap_op.c					push_op.c			\
				rotate_op.c					reverse_rotate_op.c	\
				id_utils.c					small_sort_utils.c	\
				cost_utils.c				insertion_utils.c	\
				parse_and_sort.c			insertion_utils_2.c	\
				deallocate_utils.c			print_utils.c		\
				checker_bonus.c				push_op_bonus.c		\
				reverse_rotate_op_bonus.c	rotate_op_bonus.c	\
				swap_op_bonus.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

SRCS_B = $(addprefix $(SRCS_DIR), $(SRCS_FILES_B))

OBJS = $(SRCS:%.c=%.o)

OBJS_B = $(SRCS_B:%.c=%.o)

all : lib $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

bonus : lib $(CHECKER)

$(CHECKER) : $(OBJS_B)
	$(CC) $(OBJS_B) -L ./libft -lft -o $(CHECKER)

lib :
	make -C ./libft

%.o: %.c $(INCLUDES) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

.PHONY : all lib clean fclean re bonus

clean :
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C libft
	@echo "push_swap && checker clean done"

fclean :
	$(RM) $(OBJS) $(OBJS_B)
	$(RM) $(NAME) $(CHECKER)
	make fclean -C libft
	@echo "push_swap && checker fclean done"

re : fclean all

