/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:32:08 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/12 17:35:43 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_F
#define PRINT_F

#include <stdarg.h>
#include "libft.h"

int ft_printf(const char *format, ...);
int print_char(va_list args);
int print_int(va_list args);
int print_string(va_list args);
int num_count(int nb);
int handle_format(char format, va_list args);
// int print_ptr(va_list args);
int print_percent();
int print_unsigned_decimal(va_list arg);
char *ft_itoa_unsigned(unsigned int num);
int print_hex(va_list args, int uppercase);
int unsigned_num_count(unsigned int nb);
#endif