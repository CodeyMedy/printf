/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:59:17 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/12 17:39:40 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int print_hex(va_list args, int uppercase) {
    unsigned int num = va_arg(args, unsigned int);

    char *hex_digits;
    if (uppercase) {
        hex_digits = "0123456789ABCDEF";
    } else {
        hex_digits = "0123456789abcdef";
    }

    char hex_str[9];
    int i = 0;

    if (num == 0) {
        hex_str[i++] = '0';
    } else {
        while (num > 0) {
            hex_str[i++] = hex_digits[num % 16];
            num /= 16;
        }
    }

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = hex_str[start];
        hex_str[start] = hex_str[end];
        hex_str[end] = temp;
        start++;
        end--;
    }

    hex_str[i] = '\0';
    ft_putstr_fd(hex_str, 1);
    return i;
}