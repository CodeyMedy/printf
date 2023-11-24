/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:32:39 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 15:05:49 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsinged_hexa(char *base, unsigned int n)
{
	int len;

	len = 0;
	if (n >= 16)
		len += print_unsinged_hexa(base, n / 16);
	ft_putchar(base[n % 16]);
	len++;
	return (len);
}

int print_hexa(char flag, va_list ap)
{
	char *down_hexa;
	char *up_hexa;
	unsigned int n;

	down_hexa = "0123456789abcdef";
	up_hexa = "0123456789ABCDEF";
	n = va_arg(ap, int);
	if (flag == 'x')
		return (print_unsinged_hexa(down_hexa, n));
	else if (flag == 'X')
		return (print_unsinged_hexa(up_hexa, n));
	return (0);
}
