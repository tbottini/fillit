# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberramd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 16:45:12 by yberramd          #+#    #+#              #
#    Updated: 2019/01/16 12:58:46 by tbottini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c				\
	   ft_sqrt_up.c				\
	   ft_bzero.c				\
	   ft_isalnum.c				\
	   ft_isalpha.c				\
	   ft_isascii.c				\
	   ft_isdigit.c				\
	   ft_isprint.c				\
	   ft_itoa.c				\
	   ft_memalloc.c			\
	   ft_memccpy.c				\
	   ft_memcpy.c				\
	   ft_memchr.c				\
	   ft_memcmp.c				\
	   ft_memdel.c				\
	   ft_memmove.c				\
	   ft_memset.c				\
	   ft_putchar.c				\
	   ft_putchar_fd.c			\
	   ft_putendl.c				\
	   ft_putendl_fd.c			\
	   ft_putnbr.c				\
	   ft_putnbr_fd.c			\
	   ft_putstr.c				\
	   ft_putstr_fd.c			\
	   ft_strcat.c				\
	   ft_strchr.c				\
	   ft_strclr.c				\
	   ft_strcmp.c				\
	   ft_strcpy.c				\
	   ft_strdel.c				\
	   ft_strdup.c				\
	   ft_strequ.c				\
	   ft_striter.c				\
	   ft_striteri.c			\
	   ft_strjoin.c				\
	   ft_strlcat.c				\
	   ft_strlen.c				\
	   ft_strmap.c				\
	   ft_strmapi.c				\
	   ft_strncat.c				\
	   ft_strncmp.c				\
	   ft_strncpy.c				\
	   ft_strnequ.c				\
	   ft_strnew.c				\
	   ft_strnstr.c				\
	   ft_strrchr.c				\
	   ft_strsplit.c			\
	   ft_strstr.c				\
	   ft_strsub.c				\
	   ft_strtrim.c				\
	   ft_tolower.c				\
	   ft_toupper.c				\
	   ft_lstnew.c				\
	   ft_lstdelone.c			\
	   ft_lstdel.c				\
	   ft_lstadd.c				\
	   ft_lstiter.c				\
	   ft_lstmap.c				\
	   ft_min.c					\
	   ft_max.c					\
	   ft_pow.c					\
	   ft_nbr_w.c				\
	   ft_strnchr.c				\
	   ft_strnclr.c				\
	   ft_strchr_i.c			\
	   ft_strjoin_free.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean flcean re
