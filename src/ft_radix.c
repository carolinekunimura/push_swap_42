/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:04:41 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/10 19:32:59 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_check_stack(t_numbers **stack_a)
{
	int			i;
	t_numbers	*temp;

	i = 0;
	temp = *stack_a;
	while(temp)
	{
		if (i != temp->index)
		{
			ft_printf("nao ta na ordem");
			return (0);
		}
		i++;
		temp = temp->next;
	}
	ft_printf("ta na ordem");
	return (1);
}

void	ft_push_bEck(t_numbers **stack_a, t_numbers **stack_b)
{
	while(*stack_b)
		ft_push_b(stack_a, stack_b);
//	ft_printf("PUSHBACK");	
	return ;
}

void	ft_radix(int argc, t_numbers **stack_a, t_numbers **stack_b)
{
	int	size;
	int	i;
	int	j;

	i = 1;
	size = argc;
	ft_printf("%d\n", argc);
	while (!ft_check_stack(stack_a))
	{
		j = 0;
		while(j < argc && !ft_check_stack(stack_a))
		{
			printf("==========inicio============\n");
			if (*stack_a && ((*stack_a)->index >> i) &1)
				ft_push_a(stack_a, stack_b);
			else
				ft_rotate_a(stack_a);
			j++;
//			printf("==========Stack a================\n");
//			ft_print_stack(*stack_a);
//			printf("==========Stack b================\n");
//			ft_print_stack(*stack_b);
//			sleep(1);
//			printf("==========fim====================\n");
		}
		ft_push_bEck(stack_a, stack_b);
		i++;
	}
}
