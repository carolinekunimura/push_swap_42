/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/11 14:09:28 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_free(t_numbers **stack)
{
	t_numbers *temp;

	while(*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	valid_numbers(char	**argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		temp = ft_strtrim(argv[i], " ");
		if (!temp)
			return (1);
		if (temp[j] == '-' || temp[j] == '+')
			j++;
		while (temp[j])
		{
			if (ft_isdigit(temp[j]) == 0)
			{
				free(temp);
				return (1);
			}
			j++;
		}
		free(temp);
	}
	return (0);
}

t_numbers	*ft_init_stack(int argc, char **argv, t_numbers *stack)
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
	return (stack);
}

void	ft_put_index(t_numbers *stack)
{
	int			index;
	t_numbers	*temp;
	t_numbers	*aux;

	temp = stack;
	while (temp != NULL)
	{
		index = 0;
		aux = stack;
		while (aux != NULL)
		{
			if (temp->number > aux->number)
				index++;
			aux = aux->next;
		}
		temp->index = index;
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_numbers	*stack_a;
	t_numbers	*stack_b;

	stack_a = NULL;
	if (argc < 2)
		return (1);
	if (valid_numbers(argv) != 0)
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	stack_a = ft_init_stack(argc, argv, stack_a);
	stack_b = NULL;
	if (ft_lstsize(stack_a) == 1)
		return (0);
	else if (ft_lstsize(stack_a) == 2)
		ft_sorttwo(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		ft_sortthree(&stack_a);
	else if (ft_lstsize(stack_a) > 3 && ft_lstsize(stack_a) < 6)
		ft_sort_fourfive(&stack_a, &stack_b, argc - 1);
	else
		ft_radix(argc, &stack_a, &stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
