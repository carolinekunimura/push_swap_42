/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:27:00 by ckunimur          #+#    #+#             */
/*   Updated: 2023/06/13 12:14:29 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_numbers	*ft_lstnew(char	*argv)
{
	t_numbers	*list_a;

	list_a = (t_numbers *)ft_calloc(1, sizeof(t_numbers));
	if (list_a == NULL)
		return (NULL);
	list_a->number = ft_atol(argv);
	list_a->next = NULL;
	return (list_a);
}
