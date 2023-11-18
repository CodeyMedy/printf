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

// Still needs to be fixed depending on system
char* addr_to_hex(void* addr) {
    uintptr_t address = (uintptr_t)addr;
    int address_digits = unsigned_num_count(address);
    char* hexStr = (char*)malloc(sizeof(char) * (address_digits + 3));
    if (hexStr == NULL) {
        return NULL;
    }
    const char hexDigits[] = "0123456789abcdef";
    hexStr[0] = '0';
    hexStr[1] = 'x';
    address_digits--;
    while(address_digits > 1)
    {
        hexStr[address_digits] = hexDigits[address % 16];
        address /= 16;
        address_digits--;
    }
    hexStr[18] = '\0';
    return hexStr;
}

int print_ptr(va_list args) {
    void *ptr;
    char *hex_str;

    ptr = va_arg(args, void *);
    hex_str = addr_to_hex(ptr);
    if (!hex_str) {
        return 0;
    }
    ft_putstr_fd(hex_str, 1);
    int len = (int)ft_strlen(hex_str);
    free(hex_str);
    return (len);
}
