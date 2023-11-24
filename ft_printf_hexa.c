/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:32:39 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 18:20:51 by mboukour         ###   ########.fr       */
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
	char *hexa;
	unsigned int n;
	int len;

	n = va_arg(ap, int);
	if (flag == 'x')
	{
		hexa = ft_strdup("0123456789abcdef");
		if(!hexa)
			return (-1);
		len = print_unsinged_hexa(hexa, n);
		free(hexa);
		return (len);
	}
	else if (flag == 'X')
	{
		hexa = ft_strdup("0123456789ABCDEF");
		if(!hexa)
			return (-1);
		len = print_unsinged_hexa(hexa, n);
		free(hexa);
		return (len);
	}

	return (0);
}
