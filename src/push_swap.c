/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/01 17:09:32 by ckunimur         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_numbers	*stack_a;
	t_numbers	*stack_b;

	if(argc < 3)
		return(1);
	if (valid_numbers(argv) != 0)
	{
		ft_printf("error\n");
		return(0);
	}
	stack_a = ft_init_stack(argc, argv, stack_a);
	stack_b = NULL;

	return(0);
}

