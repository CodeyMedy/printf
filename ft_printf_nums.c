/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:32:54 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 21:23:25 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimals(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr_unsigned(n);
	return (ft_unsigned_nbrlen(n));
}

int	print_decimals(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr(n);
	return (ft_nbrlen(n));
}
