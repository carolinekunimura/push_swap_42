/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/21 19:50:40 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *make_node(char *number)
{
	t_list *node;
	
	node = malloc(1 * sizeof(t_list));
	if(!node)
		return(NULL);
	node->name = ft_strdup(number);
	node->next = NULL;
	return(node);
}

void	add_back(t_list **list, t_list *node)
{
	t_list	*node;

	if(list == NULL)
		return;
	if(*list == NULL)
	{
		*list = node;
		return;
	}
	temp = *list;
	while (tem->next)
	{
		temp = temp->next;
	}
	temp->next = node;
	
}

int main(int argc, char **argv)
{
	int i;
	int

	i = 1;
	if(argc < 2)
		return(1);
	t_list	*lits_number;
	t_list	*actual_number;

	while(argv[i])
	{
		while(argv[i][j])
		{

			if(ft_isdigit(argv[i][j]) == 0)
				ft_printf("error\n");
				return(1);
			j++;
		}
		j = 0;
		i++;
	}

	actual_number = make_node(argv[i]);
	if char 
	
	add_back(&lits_number, actual_number)
	return(0);
}