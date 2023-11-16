/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:14:41 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/12 13:14:43 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_int(va_list args) {
    int num;

    num = va_arg(args, int);
    ft_putnbr_fd(num, 1);
    return num_count(num);
}
