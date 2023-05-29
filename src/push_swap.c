/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:04:38 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/29 18:09:45 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	return(1);
}

t_numbers	*ft_init_list(int argc, char **argv, t_numbers	*list)
{
	t_numbers	*temp;
	int			i;
	
	i = 1;
	list = ft_lstnew(argv[i++]);
	temp = list;
	while (i < (argc))
	{
		temp->next = ft_lstnew(argv[i]);
		temp = temp->next;
		i++;
	}
	return(list);
}

int main(int argc, char **argv)
{
	t_numbers	*list_a;

	list_a = NULL;
	if(argc < 3)
		return(1);
	list_a = ft_init_list(argc, argv, list_a);
	ft_printf("foi\n");
	return(0);
}

