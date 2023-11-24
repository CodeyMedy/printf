/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:44:14 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 16:12:39 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int print_string(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int	print_percent(void)
{
	ft_putchar('%');
	return (1);
}