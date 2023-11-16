/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:34:22 by mboukour          #+#    #+#             */
/*   Updated: 2023/11/13 21:22:11 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>


static char *pointer_to_hex(void *ptr) {
	int hex_str_len; 
	char *hex_str;

	hex_str_len = sizeof(ptr) * 2 + 1;
	*hex_str = (char *)malloc(hex_str_len);
	if(!hex_str)
		return(NULL);
	
}
int print_ptr(va_list args) {
    void *ptr;
    char *hex_str;

    ptr = va_arg(args, void *);
    hex_str = pointer_to_hex(ptr);
    if (!hex_str) {
        return 0;
    }
    ft_putstr_fd(hex_str, 1);
    int len = (int)ft_strlen(hex_str);
    free(hex_str);
    return (len);
}
