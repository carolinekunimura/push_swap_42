/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/07 18:49:35 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
		ft_printf("%s\n", argv[i]);
		i++;
	}
	return(0);
}
void	ft_print_stack(t_numbers *stack)
{
	while (stack)
	{
		ft_printf("%i\n", stack->number);
		stack = stack->next;
	}
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
	return(stack);
}

void	ft_push_a(t_numbers	**stack_a, t_numbers	**stack_b)
{
	t_numbers	*temp;
	
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next = *stack_b;
	(*stack_b) = temp;
	ft_print_stack(*stack_a);
	ft_printf("\n");
	ft_print_stack(*stack_b);
}

void	ft_push_b(t_numbers	*stack_a, t_numbers	*stack_b)
{
	t_numbers	*temp;
	
	temp = stack_b;
	stack_b = stack_b->next;
	temp->next = stack_a;
	stack_a = temp;
}

void	ft_swap(t_numbers **stack)
{
	t_numbers	*temp;
	
	if(stack == NULL)
		return ;
	if(stack != NULL && (*stack)->next != NULL)
	{
		
		temp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		temp->next = *stack;
		*stack = temp;
		ft_print_stack(*stack);	
	}
	else
		return ;
}

void	ft_rotate(t_numbers	**stack)
{
	t_numbers	*temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->next == NULL)
	{
		temp->next = *stack;
		(*stack) = (*stack)->next;
		temp->next->next = NULL;
	}
}

void	ft_rotatereverse(t_numbers **stack)
{
	t_numbers	*temp;
	t_numbers	*last;
	temp = *stack;
	
	while (temp->next->next != NULL)
		temp = temp->next;
	if(temp->next->next == NULL)
	{
		last = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack  = last;
		ft_printf("\n");
		ft_print_stack(*stack);
	}
	return ;
}
/*

int	ft_sorttwo(t_numbers	*stack_a)
{
	ft_printf("foi");
	return(0);
}
*/
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
	{
		if(stack_a->number > stack_a->next->number)
			ft_swap(&stack_a);
	}
	if(ft_lstsize(stack_a) == 3)
		ft_push_a(&stack_a, &stack_b);
	if (ft_lstsize(stack_a) > 3)
	{
		ft_rotatereverse(&stack_a);
	} 
	return(0);
}
