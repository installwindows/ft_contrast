# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 18:45:25 by varnaud           #+#    #+#              #
#    Updated: 2017/04/08 23:43:11 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_contrast
SRC = main.c \
	  sample.c \
	  write_output.c \
	  set_contrast.c \
	  read_data.c \
	  ft_strmatch.c
OBJ = $(SRC:.c=.o)
CFLAGS = -g -Ilibft -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): libft.a $(OBJ) ft_contrast.h
	gcc $(OBJ) -o $(NAME) $(CFLAGS) -Llibft -lft

libft.a:
	make -C libft
