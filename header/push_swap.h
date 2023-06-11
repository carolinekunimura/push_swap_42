/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:05:18 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/11 13:46:33 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "../libft_42/libft.h"
#include <limits.h>
#include <stdio.h>
#include "../libft_42/ft_printf.h"

int			valid_numbers(char **argv);
t_numbers	*ft_init_stack(int argc, char **argv, t_numbers	*stack);
void		ft_put_index(t_numbers *stack);
void		ft_sorttwo(t_numbers	**stack_a);
void		ft_sortthree(t_numbers **stack_a);
void		ft_sort_fourfive(t_numbers	**stack_a, t_numbers **stack_b, int argc);
int			ft_check_stack(t_numbers **stack_a);
void		ft_push_a(t_numbers	**stack_a, t_numbers	**stack_b);
void		ft_push_b(t_numbers	**stack_a, t_numbers	**stack_b);
void		ft_swap_a(t_numbers **stack);
void		ft_swap_b(t_numbers **stack);
void		ft_rotate_a(t_numbers	**stack);
void		ft_rotate_b(t_numbers	**stack);
void		ft_rotatereverse_a(t_numbers **stack);
void		ft_rotatereverse_b(t_numbers **stack);
void		ft_print_stack(t_numbers *stack);
void		ft_radix(int argc, t_numbers **stack_a, t_numbers **stack_b);
void		ft_push_back(t_numbers **stack_a, t_numbers **stack_b);
int			ft_count_digit(int argc);
void		ft_free(t_numbers **stack);

#endif
