/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:33:15 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 16:20:53 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsinged_long_hexa(char *base, long n)
{
	long len;

	len = 0;
	if (n >= 16)
		len += print_unsinged_long_hexa(base, n / 16);
	ft_putchar(base[n % 16]);
	len++;
	return (len);
}


int print_ptr(va_list ap)
{
	void			*ptr;
	int				len;
	long	address;

	ptr = va_arg(ap, void *);
	address = (long)ptr;
	ft_putstr("0x");
	len = print_unsinged_long_hexa("0123456789abcdef", address);
	return (len + 2);
}