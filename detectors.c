/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:33:35 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/21 20:51:41 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void detect_flags(char *fmt, t_flags *table)
{
    while (*fmt && (*fmt == '#' || *fmt == '0' || *fmt == '-' || *fmt == '+' || *fmt == ' '))
    {
        if (*fmt == '#' && table->hash == 0)
            table->hash = 1;
        if (*fmt == '0' && table->zero == 0)
            table->zero = 1;
        if (*fmt == '-' && table->minus == 0)
            table->minus = 1;
        if (*fmt == '+' && table->plus == 0)
            table->plus = 1;
        if (*fmt == ' ' && table->space == 0)
            table->space = 1;
        fmt++;
    }
    detect_width(fmt, table);
}

void detect_width(char *fmt, t_flags *table)
{
    char *str;
    int i;

    i = 0;
    str = ft_strnew(10);
    //if (*fmt == '*') // Should handle this somehow.
    while (*fmt && i < 11 && *fmt > '0' && *fmt < '9')
    {
        str[i] = *fmt;
        fmt++;
        i++;
    }
    table->width = ft_atoi(str);
    ft_strdel(&str);
    detect_precision(fmt, table);
}

void detect_precision(char *fmt, t_flags *table)
{
    char *str;
    int i;

    i = 0;
    table->precision = -1;
    str = ft_strnew(10);
    if (*fmt == '.')
    {
        fmt++;
        while (*fmt && i < 11 && *fmt > '0' && *fmt < '9')
        {
            str[i] = *fmt;
            fmt++;
            i++;
        }
        table->precision = ft_atoi(str);
    }
    ft_strdel(&str);
    detect_length(fmt, table);
}

void detect_length(char *fmt, t_flags *table)
{
    int check;

    check = 0;
    while (*fmt && (*fmt == 'h' || *fmt == 'l' || *fmt == 'L'))
    {
        if (((*fmt == 'h' && check == 0) || (*fmt == 'l' && check == 0) || (*fmt == 'L' && check == 0)))
        {
            table->length1 = *fmt;
            fmt++;
            check++;
        }
        if ((*fmt == 'h' && check == 1) || (*fmt == 'l' && check == 1))
        {
            table->length2 = *fmt;
            fmt++;
            check++;
        }
    }
    detect_specifier(fmt, table);
}

void detect_specifier(char *fmt, t_flags *table)
{
    char *str;
    str = "cspdiouxXf";

    while (*fmt && *str && *fmt != *str)
        str++;
    if (*fmt == *str)
    {
        table->specifier = *fmt;
        fmt++;
    }
}