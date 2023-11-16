/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:06:14 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/12 17:36:09 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsigned_decimal(va_list arg)
{
	unsigned int num;

	int i;
	char  *num_str;

	num = va_arg(arg, unsigned int);
	i = 0;
	num_str = ft_itoa_unsigned(num);
	if(!num_str)
		return (-1);
	ft_putstr_fd(num_str, 1);
	free(num_str);
	return (unsigned_num_count(num));
}