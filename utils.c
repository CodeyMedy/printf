/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:21:09 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/12 17:41:13 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int num_count(int nb)
{
    int i;

    i = 1;
    if (nb < 0)
    {
        if (nb == -2147483648)
        {
            return 11;
        }
        nb *= -1;
        i++;
    }
    while (nb >= 10)
    {
        nb /= 10;
        i++;
    }
    return (i);
}

int unsigned_num_count(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb>=10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
int handle_format(char format, va_list args) {
    if (format == 'c') {
        return print_char(args);
    } else if (format == 'i' || format == 'd') {
        return print_int(args);
    } else if (format == 's') {
        return print_string(args);
    } else if (format == '%') {
		return (print_percent(args));
	} else if (format == 'u') { 
        return (print_unsigned_decimal(args));  
    } else if (format == 'x') {
        return print_hex(args, 0);
    } else if (format == 'X') {
        return print_hex(args, 1);
    } else if (format == 'p') {
        return print_ptr(args);
    }
    return (0); // SPECEFIER UNKOWN
}


static void fill_str(char *str, unsigned int nbr, int len) {
    int index = len - 1;
    if (nbr == 0) {
        str[0] = '0';
    }
    while (nbr != 0) {
        str[index--] = (nbr % 10) + '0';
        nbr /= 10;
    }
}

char *ft_itoa_unsigned(unsigned int n) {
    int len = unsigned_num_count(n);
    char *str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL) {
        return NULL;
    }

    str[len] = '\0';
    fill_str(str, n, len);
    return str;
}
