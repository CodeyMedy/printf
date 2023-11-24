/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:29:28 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 16:41:55 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char flag, va_list ap)
{
	if (flag == 'c')
		return (print_char(ap));
	else if (flag == 's')
		return (print_string(ap));
	else if (flag == 'p')
		return (print_ptr(ap));
	else if (flag == 'd' || flag == 'i')
		return (print_decimals(ap));
	else if (flag == 'u')
		return (print_unsigned_decimals(ap));
	else if (flag == 'x' || flag == 'X')
		return (print_hexa(flag, ap));
	else if (flag == '%')
		return (print_percent());
	else
		return (0);
}

int ft_nbrlen(long long n) 
{
	int len = 0;

    if (n < 0) {
        len++;
        n = -n;
    }

	while (n > 0)
    {
        n /= 10;
        len++;
    } 
    return len;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
