/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:05:18 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/26 21:46:37 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "../libft_42/libft.h"
#include <limits.h>
#include <stdio.h>
#include "../libft_42/ft_printf.h"
/*
typedef struct s_numbers {
	int					number;
	int					index;
	struct s_numbers	*next;
} t_numbers;
*/
void		add_back(t_numbers **list, t_numbers *node);
t_numbers	*make_node(int *number);
void		add_back(t_numbers **list, t_numbers *node);
int			valid_int(char **temp);

#endif
