# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 19:31:17 by iugolin           #+#    #+#              #
#    Updated: 2022/05/26 02:35:35 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

HEADER = libft.h

RM = @rm -f

SRCS =	ft_isalpha.c		ft_isdigit.c		\
		ft_isalnum.c		ft_isascii.c		\
		ft_isprint.c		ft_strlen.c			\
		ft_memset.c			ft_bzero.c			\
		ft_memcpy.c			ft_memmove.c		\
		ft_strlcpy.c		ft_strlcat.c		\
		ft_toupper.c		ft_tolower.c		\
		ft_strchr.c			ft_strrchr.c		\
		ft_strcmp.c			ft_strncmp.c		\
		ft_memchr.c			ft_memcmp.c			\
		ft_strnstr.c		ft_atoi.c			\
		ft_calloc.c			ft_strdup.c			\
		ft_substr.c			ft_strjoin.c		\
		ft_strtrim.c		ft_split.c			\
		ft_itoa.c			ft_strmapi.c		\
		ft_striteri.c		ft_putchar_fd.c		\
		ft_putstr_fd.c		ft_putendl_fd.c		\
		ft_putnbr_fd.c		ft_strjoin_free.c	\
		get_next_line.c

OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar crs $@ $?
	@echo "\nlibft.a updated\n"

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJS)
	@echo "libft clean done"

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@echo "libft fclean done"

re : fclean all

