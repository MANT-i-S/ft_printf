/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:50:36 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/22 16:24:49 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int dispatch(va_list ap, t_flags *table)
{
    int choice;
    char *str;

    str = "cspdiouxXf";
    choice = 0;
    while(str[choice] != table->specifier)
    choice++;

    determine *options[11] = 
    {
        process_c,
        // process_s,
        // process_p,
        // process_d,
        // process_i,
        // process_o,
        // process_u,
        // process_x,
        // process_X,
        // process_f
    };
    options[choice](ap, table);
    return (0);
}