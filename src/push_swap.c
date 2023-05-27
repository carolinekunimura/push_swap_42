/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/26 21:51:07 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
/*
t_numbers *make_node(int *number)
{
	t_numbers *node;
	
	node = malloc(1 * sizeof(t_numbers));
	if(!node)
		return(NULL);
	node->number = number;
	node->next = NULL;
	return(node);
}

void	add_back(t_numbers **list, t_numbers *node)
{
	t_numbers	*temp;

	if(list == NULL)
		return;
	if(*list == NULL)
	{
		*list = node;
		return;
	}
	temp = *list;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = node;
	
}
*/
int	valid_int(char **temp)
{
	int	i;
	int numbers;

	i = 0;
	while(temp[i])
	{
		numbers = ft_atoi(temp[i]);
		if(numbers > INT_MAX || numbers < INT_MIN)
			return(0);
		i++;
	}
	
	return(1);
}
int	validate_numbers(char *argv)
{
	int		i;
	char	**temp;

	i = 0;
	while(argv[i])
	{
		if(ft_isdigit(argv[i]) == 0 && argv[i] != ' ')
		{
			ft_printf("error 1\n");
				return(0);
		}
		i++;
	}
	temp = ft_split(argv, ' ');
	if(valid_int(temp) == 0)
	{
		ft_printf("error 2\n");
		return(0);
	}
	return(1);
}

void	ft_init_list(t_numbers	*list)
{
	while (list)
	{
		ft_printf("%i\n", list->number);
		list = list->next;
	}
	
}
t_numbers	*ft_lstnew(char	*argv)
{
	t_numbers	*list_a;

	list_a = (t_numbers *)ft_calloc(1, sizeof(t_numbers));
	if (list_a == NULL)
		return (NULL);
	list_a->number = ft_atoi(argv);
	list_a->next = NULL;
	return (list_a);
}
int main(int argc, char **argv)
{
	int	i;
	t_numbers	*list_a;
	t_numbers	*temp;

	i = 1;
	list_a = NULL;
	if(argc < 2)
		return(1);
/*	if(validate_numbers(argv[1]) == 1)
	{
		ft_printf("error 3\n");
		return(1);
	}
*/
	list_a = ft_lstnew(argv[i++]);
	temp = list_a;
	while (i < (argc))
	{
		temp->next = ft_lstnew(argv[i]);
		temp = temp->next;
		i++;
	}
	ft_init_list(list_a);
	return(0);
}

