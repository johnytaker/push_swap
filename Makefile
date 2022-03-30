# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/03/30 21:16:52 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = includes/

INCLUDES = $(INCLUDES_PATH)push_swap.h

RM = @rm -rf

SRCS_DIR = sources/

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

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR = objects

OBJS_FILES = $(SRCS:%.c=%.o)

# $(OBJS_DIR):
# 	@mkdir -p $(OBJS_DIR)

all :lib $(NAME)

lib :
	make -C libft

$(NAME) : $(OBJS_FILES)
	$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBFT) -o $(NAME)

# $(OBJS_FILES): $(OBJS_DIR)/%.o: %.c $(INCLUDES) $(LIBFT)
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

%.o: %.c $(INCLUDES) $(LIBFT) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@


clean :
	$(RM) $(OBJS_FILES)
	make clean -C libft
	@echo "push_swap clean done"

fclean :
	$(RM) $(OBJS_FILES)
	$(RM) $(NAME)
	make fclean -C libft
	@echo "push_swap fclean done"

re : fclean all

.PHONY : all clean fclean re
