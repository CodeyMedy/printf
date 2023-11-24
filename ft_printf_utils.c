/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:29:28 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 19:34:44 by mboukour         ###   ########.fr       */
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
		{
			ft_putchar(flag);
			return (1);
		};
}

int ft_nbrlen(int n) 
{
	int len = 0;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
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
int ft_unsigned_nbrlen(unsigned int n) 
{
	int len = 0;

	if (n == 0)
		return (1);
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

char	*ft_strdup(char *s1)
{
	char	*copy;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
