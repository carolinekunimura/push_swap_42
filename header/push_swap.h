/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:05:18 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/01 16:51:27 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "../libft_42/libft.h"
#include <limits.h>
#include <stdio.h>
#include "../libft_42/ft_printf.h"

t_numbers	*ft_init_stack(int argc, char **argv, t_numbers	*stack);
int			valid_numbers(char **argv);

#endif
