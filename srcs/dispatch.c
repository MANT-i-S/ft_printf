/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:50:36 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:27:57 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	dispatch(va_list ap, t_flags *t)
{
	if (t->specifier == 'c')
		process_c(ap, t);
	if (t->specifier == 's')
		process_s(ap, t);
	if (t->specifier == 'p')
		process_p(ap, t);
	if (t->specifier == 'd')
		process_d(ap, t);
	if (t->specifier == 'i')
		process_i(ap, t);
	if (t->specifier == 'u')
		process_u(ap, t);
	if (t->specifier == 'o')
		process_o(ap, t);
	if (t->specifier == 'x')
		process_x(ap, t);
	if (t->specifier == 'X')
		process_xx(ap, t);
	if (t->specifier == 'f')
		process_f(ap, t);
}
