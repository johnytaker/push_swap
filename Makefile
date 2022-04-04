# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:09:12 by iugolin           #+#    #+#              #
#    Updated: 2022/04/04 15:18:46 by iugolin          ###   ########.fr        #
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

OBJS_DIR = ./objects/

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

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

OBJS_B = $(addprefix $(OBJS_DIR), $(SRCS_FILES_B:.c=.o))

all : lib temp $(NAME)

lib :
	make -C ./libft

temp :
	@mkdir -p ./objects/

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

bonus : lib $(CHECKER)

$(CHECKER) : $(OBJS_B)
	$(CC) $(OBJS_B) -L ./libft -lft -o $(CHECKER)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

.PHONY : all lib clean fclean re bonus

clean :
	$(RM) $(OBJS_DIR)
	make clean -C libft
	@echo "push_swap && checker clean done"

fclean :
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME) $(CHECKER)
	make fclean -C libft
	@echo "push_swap && checker fclean done"

re : fclean all

