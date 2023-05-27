/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:22:40 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/26 21:45:17 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_numbers *lst, void (*del)(void *))
{
	t_number	*aux;

	aux = lst->next;
	del(lst->content);
	free(lst);
	lst = aux;
}
