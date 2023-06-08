/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/08 19:07:42 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_print_stack(t_numbers *stack)
{
	while (stack)
	{
		ft_printf("%i\n", stack->number);
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
	ft_put_index(argc, temp);
	while (i < (argc))
	{
		temp->next = ft_lstnew(argv[i]);
		temp = temp->next;
		i++;
	}
	return(stack);
}

int	*ft_put_index(int argc, t_numbers *temp)
{
	int	i;
	int	j;
	int	*index;

	i = 1;
	index = (int)*ft_calloc(sizeof(int), argc);
	while(i < argc)
	{
		j = 2;
		while(j < argc)
		{
			if(argv[i] > argv[j])
				index[i] += 1;
			j++;
			i++;
		}
	}
	return (&index);
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
	if((*stack_a)->number < ((*stack_a)->next->number) && (*stack_a)->next->number < ((*stack_a)->next->next->number))
		return ;
	if((*stack_a)->number > ((*stack_a)->next->number) && (*stack_a)->next->number > ((*stack_a)->next->next->number))
	{
		ft_swap_a(&*stack_a);
		ft_rotatereverse_a(&*stack_a);
	}
	while (!((*stack_a)->number < ((*stack_a)->next->number) && (*stack_a)->next->number < ((*stack_a)->next->next->number)))
	{
		if((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->number < (*stack_a)->next->next->number)
			ft_rotatereverse_a(&*stack_a);
		if((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->next->number < (*stack_a)->next->next->number)
			ft_rotate_a(stack_a);
	}
}

/*
void	ft_sortfour(t_numbers	**stack_a, t_numbers **stack_b)
{
	if((*stack_a)->number < (*stack_a)->next->number && (*stack_a)->next->number < (*stack_a)->next->next->number && (*stack_a)->next->next->number < (*stack_a)->next->next->next->number)
		return ;
	while(!((*stack_a)->number < (*stack_a)->next->number && (*stack_a)->next->number < (*stack_a)->next->next->number && (*stack_a)->next->next->number < (*stack_a)->next->next->next->number))
	{
		if((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->number > (*stack_a)->next->next->number && (*stack_a)->number > (*stack_a)->next->next->next->number)
			ft_rotate_a(stack_a);
		if((*stack_a)->next->next->number > (*stack_a)->number && (*stack_a)->next->next->next->number < (*stack_a)->next->number && (*stack_a)->next->number < (*stack_a)->number)
			ft_swap_a(stack_a);
		if((*stack_a)->number < (*stack_a)->next->number)
		{
			ft_push_a(stack_a, stack_b);
			ft_swap_a(stack_a);
			ft_push_b(stack_a, stack_b);
		}
		if((*stack_a)->number > (*stack_a)->next->number)
			ft_swap_a(stack_a);
		if((*stack_a)->next->next->next->number < (*stack_a)->number && (*stack_a)->next->next->next->number < (*stack_a)->next->next->number && (*stack_a)->next->next->next->number < (*stack_a)->next->number)
			ft_rotate_a(stack_a);
	}
	return ;

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
		ft_sorttwo(&stack_a);
	if(ft_lstsize(stack_a) == 3)
		ft_sortthree(&stack_a);
//	if(ft_lstsize(stack_a) == 4)
//		ft_sortfour(&stack_a, &stack_b);
	ft_print_stack(stack_a);
	ft_printf("\n");
	ft_print_stack(stack_b);
	return(0);
}
