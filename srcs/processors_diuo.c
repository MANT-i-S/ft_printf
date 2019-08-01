/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processors_diuo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:56:56 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 16:20:20 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	process_d(va_list ap, t_flags *t)
{
	intmax_t	num;
	char		*out;

	num = cast_int(ap, t);
	if (num < -9223372036854775807)
	{
		out = ft_strnew(25);
		out = "-9223372036854775808";
		print_di(out, t);
	}
	else if (num == 0 && t->prec == 0)
	{
		out = ft_strnew(0);
		print_di(out, t);
	}
	else
	{
		out = ultra_itoa(num);
		print_di(out, t);
		ft_strdel(&out);
	}
}

void	process_i(va_list ap, t_flags *t)
{
	intmax_t	num;
	char		*out;

	num = cast_int(ap, t);
	if (num < -9223372036854775807)
	{
		out = ft_strnew(25);
		out = "-9223372036854775808";
		print_di(out, t);
	}
	else if (num == 0 && t->prec == 0)
	{
		out = ft_strnew(0);
		print_di(out, t);
	}
	else
	{
		out = ultra_itoa(num);
		print_di(out, t);
		ft_strdel(&out);
	}
}

void	process_u(va_list ap, t_flags *t)
{
	uintmax_t	num;
	char		*out;

	num = cast_uns_int(ap, t);
	out = u_ultra_itoa(num);
	print_uoxx(out, t);
	ft_strdel(&out);
}

void	process_o(va_list ap, t_flags *t)
{
	uintmax_t	num;
	char		*out;
	int			i;

	i = 0;
	num = cast_int(ap, t);
	if (num == 0 && t->prec == 0)
		out = ft_strnew(0);
	else
	{
		out = ft_strnew(25);
		if (num == 0)
			out[i] = '0';
		while (num)
		{
			out[i++] = (num % 8) + 48;
			num = num / 8;
		}
		ft_strrot(out);
	}
	print_uoxx(out, t);
	ft_strdel(&out);
}
