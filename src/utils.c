/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:13:58 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/13 14:11:15 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_check_stack(t_numbers **stack_a)
{
	t_numbers	*temp_one;
	t_numbers	*temp_two;

	temp_one = *stack_a;
	temp_two = (*stack_a)->next;
	while (temp_one->next != NULL)
	{
		if (temp_one->index > temp_two->index)
			return (1);
		temp_one = temp_one->next;
		temp_two = temp_two->next;
	}
	return (0);
}

int	ft_check_duplicate(t_numbers **stack_a)
{
	t_numbers	*temp_one;
	t_numbers	*temp_two;

	temp_one = *stack_a;
	while (temp_one)
	{
		if (temp_one->number > INT_MAX || temp_one->number < INT_MIN)
			return (1);
		temp_two = temp_one->next;
		while (temp_two)
		{
			if (temp_one->number == temp_two->number)
				return (1);
			temp_two = temp_two->next;
		}
		temp_one = temp_one->next;
	}
	return (0);
}

void	rotate_rotate(t_numbers **stack_a, t_numbers **stack_b)
{
	t_numbers	*temp_a;
	t_numbers	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	if (stack_a == NULL || stack_b == NULL)
		return ;
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	if (temp_a->next == NULL)
	{
		temp_a->next = *stack_a;
		(*stack_a) = (*stack_a)->next;
		temp_a->next->next = NULL;
	}
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	if (temp_b->next == NULL)
	{
		temp_b->next = *stack_b;
		(*stack_b) = (*stack_b)->next;
		temp_b->next->next = NULL;
	}
	ft_printf("rr\n");
}

void	swap_swap(t_numbers **stack_a, t_numbers **stack_b)
{
	t_numbers	*temp_a;
	t_numbers	*temp_b;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp_a = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		temp_a->next = *stack_a;
		*stack_a = temp_a;
	}
	if (stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp_b = (*stack_b)->next;
		(*stack_b)->next = (*stack_b)->next->next;
		temp_b->next = *stack_b;
		*stack_b = temp_b;
	}
	ft_printf("ss\n");
}
