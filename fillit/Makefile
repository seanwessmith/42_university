# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtam <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 11:28:03 by vtam              #+#    #+#              #
#    Updated: 2016/12/03 23:05:51 by vtam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = fillit
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
FILES    =	ft_open \
			ft_tetlstnew \
			ft_tetlstadd \
			ft_initmap \
			ft_place \
			main \

LIBFLAG   = -L Libft -lft
SRC_FILES = $(addprefix $(SRC_PATH), $(addsuffix .c , $(FILES)))

OBJ_FILES = $(addsuffix .o, $(FILES))

HDR_PATH  = ./includes/
SRC_PATH  = ./src/
LIB_PATH  = ./Libft/
LIB       = ./Libft/libft.a
LIBINC    = -I $(LIB_PATH)
HDR       = -I $(HDR_PATH)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIB)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) $(LIBFLAG) $(HDR) $(LIBINC)

$(OBJ_FILES):
	$(CC) $(CFLAGS) -c $(SRC_FILES) $(HDR) $(LIBINC)

$(LIB):
	make -C $(LIB_PATH)

clean:
	rm -f $(OBJ_FILES)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
