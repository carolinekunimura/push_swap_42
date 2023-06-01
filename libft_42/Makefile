# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 18:59:32 by coder             #+#    #+#              #
#    Updated: 2023/05/31 16:20:06 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_memset.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strchr.c\
		ft_strnstr.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_atol.c ft_calloc.c ft_strdup.c ft_strrchr.c\
		ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c\
		ft_strmapi.c ft_itoa.c ft_strtrim.c ft_split.c ft_printf.c ft_checkflag.c\
		ft_putchar.c ft_puthexa.c ft_putint.c ft_putstr.c ft_putunsigned.c ft_putpointer.c ft_lstnew.c ft_lstsize.c\

OBJ	= $(SRC:%.c=%.o)

FLAG = -Wall \
	-Werror \
	-Wextra \
	-g3

all:	$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):	$(SRC)
	gcc $(FLAG) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
