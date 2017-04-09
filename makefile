# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 18:45:25 by varnaud           #+#    #+#              #
#    Updated: 2017/04/08 19:53:45 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_contrast
SRC = main.c
OBJ = $(SRC:.c=.o)
CFLAGS = -g -Ilibft -Llibft -lft
CC = gcc

all: $(NAME)

$(NAME): libft.a $(SRC)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

libft.a:
	make -C libft
