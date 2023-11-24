/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:24:06 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/24 21:16:40 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		handle_format(char flag, va_list ap);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_unsigned(unsigned int nb);
int		print_char(va_list ap);
int		print_string(va_list ap);
int		print_hexa(char flag, va_list ap);
int		print_unsigned_decimals(va_list ap);
int		print_ptr(va_list ap);
int		print_decimals(va_list ap);
int		print_percent(void);
int		print_unsinged_hexa(char *base, unsigned int n);
void	ft_putnbr(int n);
char	*ft_strdup(char *s1);
int		ft_nbrlen(int n);
int		ft_unsigned_nbrlen(unsigned int n);
#endif