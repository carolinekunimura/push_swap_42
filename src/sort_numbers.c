/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:03:13 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/10 18:11:18 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sorttwo(t_numbers	**stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		ft_swap_a(&*stack_a);
	else
		return ;
}

void	ft_sortthree(t_numbers	**stack_a)
{
	if ((*stack_a)->number > ((*stack_a)->next->number)
		&& (*stack_a)->next->number > ((*stack_a)->next->next->number))
	{
		ft_swap_a(&*stack_a);
		ft_rotatereverse_a(&*stack_a);
	}
	while (!((*stack_a)->number < ((*stack_a)->next->number)
			&& (*stack_a)->next->number < ((*stack_a)->next->next->number)))
	{
		if ((*stack_a)->number > (*stack_a)->next->number
			&& (*stack_a)->number < (*stack_a)->next->next->number)
			ft_swap_a(stack_a);
		if ((*stack_a)->number > (*stack_a)->next->number
			&& (*stack_a)->next->number < (*stack_a)->next->next->number)
			ft_rotate_a(stack_a);
		if ((*stack_a)->number < (*stack_a)->next->number
			&& (*stack_a)->next->number > (*stack_a)->next->next->number)
		{
			ft_swap_a(stack_a);
			ft_rotate_a(stack_a);
		}
	}
}

void	ft_sort_fourfive(t_numbers **stack_a, t_numbers **stack_b, int argc)
{
	t_numbers	*temp;
	int			i;

	i = 0;
	while (i < argc)
	{
		temp = *stack_a;
		if (temp->index < 2)
			ft_push_a(stack_a, stack_b);
		else
			ft_rotate_a(stack_a);
		i++;
	}
	if (ft_lstsize(*stack_a) == 3)
		ft_sortthree(stack_a);
	if (ft_lstsize(*stack_a) == 2)
		ft_sorttwo(stack_a);
	if ((*stack_b)->number < (*stack_b)->next->number)
		ft_swap_b(stack_b);
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	return ;
}