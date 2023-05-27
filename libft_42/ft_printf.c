/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:26:54 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/26 16:12:40 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *param, ...)
{
	int		count;
	va_list	list;

	count = 0;
	if (!param)
		return (-1);
	va_start(list, param);
	while (*param)
	{
		if (*param == '%')
		{
			param++;
			count += ft_checkflag(*param, list);
		}
		else
			count += write(1, param, 1);
		param++;
	}
	va_end(list);
	return (count);
}
