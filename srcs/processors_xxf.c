/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processors_xxf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:17:33 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:27:35 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	process_x(va_list ap, t_flags *t)
{
	uintmax_t	num;
	char		*out;
	int			i;

	i = 0;
	num = cast_uns_int(ap, t);
	if (num == 0 && t->prec == 0)
		out = ft_strnew(0);
	else
	{
		out = ft_strnew(25);
		if (num == 0)
			out[i] = '0';
		while (num)
		{
			if (num % 16 < 10)
				out[i++] = (num % 16) + 48;
			else
				out[i++] = (num % 16) - 10 + 97;
			num = num / 16;
		}
		ft_strrot(out);
	}
	print_uoxx(out, t);
	ft_strdel(&out);
}

void	process_xx(va_list ap, t_flags *t)
{
	uintmax_t	num;
	char		*out;
	int			i;

	i = 0;
	num = cast_uns_int(ap, t);
	if (num == 0 && t->prec == 0)
		out = ft_strnew(0);
	else
	{
		out = ft_strnew(25);
		if (num == 0)
			out[i] = '0';
		while (num)
		{
			if (num % 16 < 10)
				out[i++] = (num % 16) + 48;
			else
				out[i++] = (num % 16) - 10 + 65;
			num = num / 16;
		}
		ft_strrot(out);
	}
	print_uoxx(out, t);
	ft_strdel(&out);
}

void	process_f(va_list ap, t_flags *t)
{
	long double	longnum;
	double		num;
	char		*out;

	longnum = 0;
	num = 0;
	out = ft_strnew(50);
	if (t->length1 == 'L')
	{
		longnum = (va_arg(ap, long double));
		out = long_double_itoa(longnum, out, t);
	}
	else
	{
		num = (va_arg(ap, double));
		out = double_itoa(num, out, t);
	}
	print_f(out, t);
	ft_strdel(&out);
}
