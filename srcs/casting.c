/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:27:50 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:27:52 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	cast_int(va_list ap, t_flags *t)
{
	if (t->length1)
	{
		if (t->length1 == 'l' && t->length2 == 'l')
			return (va_arg(ap, long long));
		else if (!t->length2 && t->length1 == 'l')
			return (va_arg(ap, long));
		else if (!t->length2 && t->length1 == 'h')
			return ((short)va_arg(ap, int));
		else if (t->length2 == 'h' && t->length1 == 'h')
			return ((char)va_arg(ap, int));
	}
	return (va_arg(ap, int));
}

uintmax_t	cast_uns_int(va_list ap, t_flags *t)
{
	if (t->length1)
	{
		if (t->length1 == 'l' && t->length2 == 'l')
			return (va_arg(ap, unsigned long long));
		else if (!t->length2 && t->length1 == 'l')
			return (va_arg(ap, unsigned long));
		else if (!t->length2 && t->length1 == 'h')
			return ((short)va_arg(ap, unsigned int));
		else if (t->length2 == 'h' && t->length1 == 'h')
			return ((char)va_arg(ap, unsigned int));
	}
	return (va_arg(ap, unsigned int));
}
