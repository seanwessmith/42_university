# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssmith <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 03:44:00 by ssmith            #+#    #+#              #
#    Updated: 2017/03/08 13:14:01 by ssmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	lem_in

SRC	=		lemin.c \
			parsing.c \
			init.c \
			solve.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft/includes
LIBLINK	= -L./libft -lft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(LIBLINK)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
