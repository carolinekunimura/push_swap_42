# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:04:45 by ckunimur          #+#    #+#              #
#    Updated: 2023/05/22 17:30:43 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./src/push_swap.c $(PATH_LIBFT)libft.a

FLAGS = -Wall -Wextra -Werror

PATH_LIBFT = ./libft_42/


all: $(PATH_LIBFT)libft.a
	echo socorrro
	gcc $(SRC) $(FLAGS) -o $(NAME)

libft:
	make -C $(PATH_LIBFT)

clean:
	rm -f $(NAME) $(PATH_LIBFT)libft.a
	make clean -C $(PATH_LIBFT)
