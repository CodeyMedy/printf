/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:14:53 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/12 16:12:05 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(va_list args) {
    char *str;

    str = va_arg(args, char *);
    ft_putstr_fd(str, 1);
    return ((int)ft_strlen(str));
}
