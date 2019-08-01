/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:39:27 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:59:16 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		itos(unsigned long long x, char str[], int d, t_flags *t)
{
	int	i;

	i = 0;
	if (x == 0)
		str[i++] = '0';
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	if (t->float_sign)
	{
		str[i++] = '-';
		t->float_sign = 0;
	}
	ft_strrot(str);
	str[i] = '\0';
	return (i);
}

char	*long_double_itoa(long double n, char *res, t_flags *t)
{
	long double fpart;
	int			i[3];

	i[1] = 6;
	i[2] = (unsigned long long)n;
	fpart = n - (long double)i[2];
	if (t->prec != -1)
		i[1] = t->prec;
	if (i[2] < 0)
	{
		i[2] = -i[2];
		fpart = -fpart;
		t->float_sign = 1;
	}
	i[0] = itos(i[2], res, 0, t);
	if (i[1] != 0)
	{
		res[i[0]] = '.';
		if (fpart == 0)
			t->float_zeros++;
		while (i[1]-- > 0)
			fpart = fpart * 10;
		itos((unsigned long long)fpart, res + i[0] + 1, i[1], t);
	}
	return (res);
}

char	*double_itoa(double n, char *res, t_flags *t)
{
	double	fpart;
	int		i[3];

	i[1] = 6;
	i[2] = (unsigned long long)n;
	fpart = n - (double)i[2];
	if (t->prec != -1)
		i[1] = t->prec;
	if (i[2] < 0)
	{
		i[2] = -i[2];
		fpart = -fpart;
		t->float_sign = 1;
	}
	i[0] = itos(i[2], res, 0, t);
	if (i[1] != 0)
	{
		res[i[0]] = '.';
		if (fpart == 0)
			t->float_zeros++;
		while (i[1]-- > 0)
			fpart = fpart * 10;
		itos((unsigned long long)fpart, res + i[0] + 1, i[1], t);
	}
	return (res);
}
