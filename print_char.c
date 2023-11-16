/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:58:20 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/12 13:31:42 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(va_list args) {
    char c;

    c = va_arg(args, int);
    ft_putchar_fd(c, 1);
    return 1;
}
