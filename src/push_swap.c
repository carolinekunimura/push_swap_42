/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/22 17:28:01 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	int i;
	char **temp;

	i = 0;
	while(argv[i])  // i = 0
	{
		if(ft_isdigit(argv[i]) == 0 && argv[i] != ' ') // argv[i] = 4
		{
			printf("error 1\n");
				return(0);
		}
		i++; // i = 1
	}
	temp = ft_split(argv, ' ');
	if(valid_int(temp) == 0)
	{
		printf("error 2\n");
		return(0);
	}
	return(0);
}

int main(int argc, char **argv)
{
	
	if(argc < 2)
		return(1);
//	t_numbers	*list_number;
//	t_numbers	*actual_number;

	if(validate_numbers(argv[1]) == 1)
	{
		printf("error 3\n");
		return(1);
	}
//	actual_number = make_node(argv[i]);
//	add_back(&lits_number, actual_number);
	return(0);
}