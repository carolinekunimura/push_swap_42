/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:04:41 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:44 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_count_digit(int argc)
{
	int	count;

	count = 0;
	while (argc != 0)
	{
		argc /= 2;
		count++;
	}
	return count;
}

void	ft_push_back(t_numbers **stack_a, t_numbers **stack_b)
{
	while(*stack_b)
		ft_push_a(stack_a, stack_b);
	return ;
}

void	ft_radix(int argc, t_numbers **stack_a, t_numbers **stack_b)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	size = ft_count_digit(argc - 1);
	while (i < size)
	{
		j = 0;
		while(j < argc - 1)
		{
			if (((*stack_a)->index >> i) & 1)
				ft_rotate_a(stack_a);
			else
				ft_push_b(stack_a, stack_b);
			j++;
		}
		ft_push_back(stack_a, stack_b);
		i++;
	}
}
