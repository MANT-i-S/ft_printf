/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transistors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:37:51 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/22 16:24:48 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    begin(char *fmt, t_flags *table)
{
    while(*fmt)
    {
        if (*fmt != '%')
        {
        ft_putchar(*fmt);
        fmt++;
        }
        if (*fmt == '%')
        {
            fmt++;
            if (*fmt == '%')
            ft_putchar(*fmt);
            else if (*fmt && *fmt != '%')
            {
            detect_flags(fmt, table);
            break;
            }
        }
    }
}

int process_c(va_list ap, t_flags *table)
{
    char *str;
    char spec;
    spec = table->specifier;
    str = va_arg(ap, char*);
    return (0);
}
