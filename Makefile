# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:04:45 by ckunimur          #+#    #+#              #
#    Updated: 2023/06/01 13:38:19 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./src/push_swap.c $(PATH_LIBFT)libft.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

PATH_LIBFT = ./libft_42/


all: libft
	gcc -g $(SRC) $(FLAGS) $(PATH_LIBFT)libft.a -o $(NAME)

libft:
	make -C $(PATH_LIBFT)

clean:
	rm -f $(NAME) $(PATH_LIBFT)libft.a
	make clean -C $(PATH_LIBFT)
