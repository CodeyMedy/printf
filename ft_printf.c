/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:24:42 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 21:22:06 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_non_format(const char *format, int *i)
{
	int	count;

	count = 0;
	while (format[*i] && format[*i] != '%')
	{
		ft_putchar(format[*i]);
		(*i)++;
		count++;
	}
	return (count);
}

int	start_printf(const char *format, va_list ap)
{
	int		i;
	int		count;
	int		check;

	i = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	if (format[i] == '%' && format[i + 1] == '\0')
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			check = handle_format(format[++i], ap);
			if (check == -1)
				return (-1);
			count += check;
			i++;
		}
		else
			count += handle_non_format(format, &i);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = start_printf(format, ap);
	va_end(ap);
	return (count);
}
