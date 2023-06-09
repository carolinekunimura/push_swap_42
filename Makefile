# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:04:45 by ckunimur          #+#    #+#              #
#    Updated: 2023/06/13 10:38:20 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = $(PATH_SRC)push_swap.c $(PATH_SRC)mov_a.c $(PATH_SRC)mov_b.c  $(PATH_LIBFT)libft.a $(PATH_SRC)ft_radix.c $(PATH_SRC)ft_sort_numbers.c $(PATH_SRC)utils.c

PATH_SRC = ./src/

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

fclean: clean
	rm -rf $(NAME)

re: fclean all
