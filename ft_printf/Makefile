# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssmith <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 08:55:56 by ssmith            #+#    #+#              #
#    Updated: 2017/01/19 14:24:43 by ssmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	+= 	ft_printf.c

NAME	 	=	libftprintf.a

LIBFT		=	libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(addprefix srcs/, $(FILENAMES))
OBJS		=	$(addprefix build/, $(FILENAMES:.c=.o))

.PHONY:		all clean fclean re

all: $(NAME) 

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) -I includes/ -c $< -o $@

$(NAME): $(OBJS) 
	ar -x libft/libft.a
	ar rcs $@ $(OBJS) *.o
	ranlib $@
	rm *.o

clean:
	rm -rf build/
	rm -rf __.SYMDEF\ SORTED
	rm -rf __.SYMDEF

fclean: clean
	rm -f $(NAME)

re: fclean all
