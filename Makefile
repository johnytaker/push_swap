# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/03/31 22:03:57 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

PUSH_SWAP = push_swap

CHECKER = checker

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = includes/

INCLUDES = $(INCLUDES_PATH)push_swap.h

RM = @rm -rf

SRCS_DIR = sources/

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
				checker_bonus.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

SRCS_B = $(addprefix $(SRCS_DIR), $(SRCS_FILES_B))

OBJS = $(SRCS:%.c=%.o)

OBJS_B = $(SRCS_B:%.c=%.o)

# $(OBJS_DIR):
# 	@mkdir -p $(OBJS_DIR)

# all : lib $(NAME)

$(NAME) : lib push_swap checker

all : $(NAME)

lib :
	make -C libft

# $(NAME) : $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# $(OBJS_FILES): $(OBJS_DIR)/%.o: %.c $(INCLUDES) $(LIBFT)
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

%.o: %.c $(INCLUDES) $(LIBFT) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

push_swap : $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(PUSH_SWAP)

checker : $(OBJS_B)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(CHECKER)

bonus :
	make "OBJS=$(OBJS_B)" all

clean :
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C libft
	@echo "push_swap && checker clean done"

fclean :
	$(RM) $(OBJS) $(OBJS_B)
	$(RM) $(PUSH_SWAP) $(CHECKER)
	make fclean -C libft
	@echo "push_swap && checker fclean done"

re : fclean all

.PHONY : all bonus clean fclean re
