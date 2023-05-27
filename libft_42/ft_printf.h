/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:42:47 by ckunimur          #+#    #+#             */
/*   Updated: 2022/11/10 17:28:07 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define BASEISUPPER "0123456789ABCDEF"
# define BASEISLOWER "0123456789abcdef"

//functions

int	ft_printf(const char *param, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_checkflag(char flag, va_list list);
int	ft_puthexa(unsigned long n, int flag);
int	ft_putint(int n);
int	ft_putpointer(unsigned long int ptr);
int	ft_putunsigned(unsigned int nbr);

#endif