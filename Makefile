# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberramd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 18:09:49 by yberramd          #+#    #+#              #
#    Updated: 2019/01/15 18:45:05 by tbottini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = lib_tetromino.c	\
	   parseur.c		\
	   lib_map.c		\
	   fillit.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) fillit.h
	make -C libft/
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) libft/libft.a

clean :
	make clean -C libft/
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft/
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean flcean re
