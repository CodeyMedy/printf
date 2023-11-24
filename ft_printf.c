/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:24:42 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 19:44:10 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;
    int check;

	va_start(ap, format);
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
            if(check == -1)
                return (-1);
			count += check;
			i++;
		}
		else
		{
			ft_putchar(format[i++]);
			count++;
		}
	}
	return (count);
}
