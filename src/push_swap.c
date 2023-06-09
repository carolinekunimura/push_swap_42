/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/09 19:56:18 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_print_stack(t_numbers *stack)
{
	while (stack)
	{
		ft_printf("%i\n", stack->number);
//		ft_printf("%i\n", stack->index);
		stack = stack->next;
	}
}

int	valid_numbers(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		if(argv[i][j] == ' ' || argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while(argv[i][j])
		{
			if(ft_isdigit(argv[i][j]) == 0 && (argv[i][j] != ' ' || ft_isdigit(argv[i][j + 1]) == 0))
			{
				ft_printf("not number\n");
				return(1);
			}
			j++;
		}
		i++;
	}
	return(0);
}

t_numbers	*ft_init_stack(int argc, char **argv, t_numbers	*stack)
{
	t_numbers	*temp;
	int			i;
	
	i = 1;
	stack = ft_lstnew(argv[i++]);
	temp = stack;
	while (i < (argc))
	{
		temp->next = ft_lstnew(argv[i]);
		temp = temp->next;
		i++;
	}
	ft_put_index(stack);
	return(stack);
}

void	ft_put_index(t_numbers *stack)
{
	int 		index;
	t_numbers	*temp;
	t_numbers	*aux;

	temp = stack;
	while (temp != NULL)
	{
		index = 0;
		aux = stack;
		while(aux != NULL)
		{
			if(temp->number > aux->number)
				index++;
			aux = aux->next;	
		}
		temp->index = index;
		temp = temp->next;
	}
}

void	ft_sorttwo(t_numbers	**stack_a)
{
	if((*stack_a)->number > (*stack_a)->next->number)
		ft_swap_a(&*stack_a);
	else
		return ;
}

void	ft_sortthree(t_numbers **stack_a)
{
	if((*stack_a)->number > ((*stack_a)->next->number) && (*stack_a)->next->number > ((*stack_a)->next->next->number))
	{
		ft_swap_a(&*stack_a);
		ft_rotatereverse_a(&*stack_a);
	}
	while (!((*stack_a)->number < ((*stack_a)->next->number) && (*stack_a)->next->number < ((*stack_a)->next->next->number)))
	{
		if((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->number < (*stack_a)->next->next->number)
			ft_swap_a(stack_a);
		if((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->next->number < (*stack_a)->next->next->number)
			ft_rotate_a(stack_a);
		if((*stack_a)->number < (*stack_a)->next->number && (*stack_a)->next->number > (*stack_a)->next->next->number)
		{
			ft_swap_a(stack_a);
			ft_rotate_a(stack_a);
		}
	}
	return ;
}

void	ft_sort_fourfive(t_numbers	**stack_a, t_numbers **stack_b, int argc)
{
	t_numbers	*temp;
	int			i;

	i = 0;
	while (i < argc)
	{
		temp = *stack_a;
		if(temp->index < 2)
			ft_push_a(stack_a, stack_b);
		else
			ft_rotate_a(stack_a);
		i++;
	}
	ft_sortthree(stack_a);
//	ft_print_stack(*stack_b);
	if((*stack_b)->number < (*stack_b)->next->number)
		ft_swap_b(stack_b);
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	return ;
}

int main(int argc, char **argv)
{
	t_numbers	*stack_a;
	t_numbers	*stack_b;

	stack_a = NULL;
	if(argc < 3)
		return(1);
	if (valid_numbers(argv) != 0)
	{
		ft_putstr_fd("error\n", 2);
		return(0);
	}
	stack_a = ft_init_stack(argc, argv, stack_a);
	stack_b = NULL;

	if(ft_lstsize(stack_a) == 1)
		return(0);
	if(ft_lstsize(stack_a) == 2)
		ft_sorttwo(&stack_a);
	if(ft_lstsize(stack_a) == 3)
		ft_sortthree(&stack_a);
	if(ft_lstsize(stack_a) > 3 && ft_lstsize(stack_a) < 6)
		ft_sort_fourfive(&stack_a, &stack_b, argc - 1);
	ft_printf("\n");
	ft_printf("\n");
	ft_print_stack(stack_a);
//	ft_print_stack(stack_b);
	return(0);
}
