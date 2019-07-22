/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:43:26 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/22 15:47:10 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    t_flags table;
    char    *str;

    ft_strnew(sizeof(table));
    ft_bzero(&table, sizeof(t_flags));
    va_start(ap, fmt);
    str = (char *)fmt;
    begin(str, &table);
    printf("hash %d\n", table.hash);
    printf("zero %d\n", table.zero);
    printf("width %d\n", table.width);
    printf("precision %d\n", table.precision);
    printf("length1 %c\n", table.length1);
    printf("length2 %c\n", table.length2);
    printf("specifier %c\n", table.specifier);
    //str = va_arg(ap, char*); // give correct type thrue dispatch depend on specifier.
    dispatch(ap, &table); //Figure out how to use int.
    va_end(ap);
    return(0);
}

#include "ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("Hey here is character\n%c", "another string");
    ft_putchar(42);
}