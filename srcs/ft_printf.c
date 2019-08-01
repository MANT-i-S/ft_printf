/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:43:26 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 17:55:12 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_flags	*t;
	char	*str;
	int		total;

	total = 0;
	t = (t_flags*)malloc(sizeof(t_flags));
	va_start(ap, fmt);
	str = (char *)fmt;
	while (*str)
	{
		ft_bzero(t, sizeof(t_flags));
		str = begin(str, t);
		if (t->specifier)
			dispatch(ap, t);
		total = total + t->glob_count;
	}
	va_end(ap);
	return (total);
}
