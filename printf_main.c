/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:34:16 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/15 00:33:47 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int ft_printf(const char *format, ...) {
    int i, count;
    va_list args;

    va_start(args, format);
    i = 0;
    count = 0;
    if(write(1, "", 0) == -1)
        return (-1);
    while (format[i]) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            count += handle_format(format[++i], args);
            i++;
        } else {
            ft_putchar_fd(format[i++], 1);
            count++;
        }
    }
    va_end(args);
    return count;
}

int main() {
    char c = 'W';
    int i = -2147483648; // Minimum value for a signed int
    unsigned int u = 4294967295; // Maximum value for an unsigned int
    char *s = "";
    int x = 0;

    int res1, res2;

    res1 = printf("Character: %c\n", c);
    res2 = ft_printf("Character: %c\n", c);
    printf("res1 = %d, res2 = %d\n", res1, res2);

    res1 = printf("Integer: %d\n", i);
    res2 = ft_printf("Integer: %d\n", i);
    printf("res1 = %d, res2 = %d\n", res1, res2);

    res1 = printf("String: %s\n", s);
    res2 = ft_printf("String: %s\n", s);
    printf("res1 = %d, res2 = %d\n", res1, res2);

    res1 = printf("Percent: %%\n");
    res2 = ft_printf("Percent: %%\n");
    printf("res1 = %d, res2 = %d\n", res1, res2);

    res1 = printf("Unsigned int: %u\n", u);
    res2 = ft_printf("Unsigned int: %u\n", u);
    printf("res1 = %d, res2 = %d\n", res1, res2);

    res1 = printf("Hexa lowercase: %x\n", x);
    res2 = ft_printf("Hexa lowercase: %x\n", x);
    printf("res1 = %d, res2 = %d\n", res1, res2);

    res1 = printf("Hexa uppercase: %X\n", x);
    res2 = ft_printf("Hexa uppercase: %X\n", x);
    printf("res1 = %d, res2 = %d\n", res1, res2);

    return 0;
}