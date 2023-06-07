/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/07 17:56:14 by ckunimur         ###   ########.fr       */
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
	ft_printf("is number\n");
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
	ft_print_stack(stack);
	return(stack);
}

void	ft_push_a(t_numbers	*stack_a, t_numbers	*stack_b)
{
	t_numbers	*temp;
	
	temp = stack_a;
	stack_a = stack_a->next;
	temp->next = stack_b;
	stack_b = temp;
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
	}
	else
		return ;
}

/*

int	ft_rotate(t_numbers	*stack)
{

}

int	ft_rotatereverse(t_numbers *stack)
{

}

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
/*	if(ft_lstsize(stack_a) == 3)

	if(ft_lstsize(stack_a) == 1)
		return(0);
	if(ft_lstsize(stack_a) == 2)
		ft_sorttwo(stack_a);
		ft_sortthree(stack_a);
	if (ft_lstsize(stack_a) > 3)
	{
		radixx;
	} 
*/	return(0);
}
