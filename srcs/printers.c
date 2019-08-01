/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:49:01 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 18:01:11 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar_count(char c, t_flags *t)
{
	write(1, &c, 1);
	t->glob_count++;
}

void	ft_putstr_count(char const *s, t_flags *t)
{
	int	len;
	int	count;

	len = ft_strlen(s);
	count = t->prec - len;
	if (len > 0 && len > t->prec && t->prec != -1
	&& t->specifier == 's')
	{
		write(1, s, t->prec);
		t->glob_count = t->glob_count + t->prec;
	}
	else if (len > 0)
	{
		write(1, s, len);
		t->glob_count = t->glob_count + len;
	}
}

void	print_s(char *s, t_flags *t)
{
	int	count;
	int	len;

	len = ft_strlen(s);
	count = t->width;
	if (len > t->prec && t->prec != -1)
		count = count - t->prec;
	else if (t->width)
		count = count - len;
	if (t->plus || t->space)
		count--;
	if (t->minus && count > 0)
	{
		ft_putstr_count(s, t);
		while (count-- > 0)
			ft_putchar_count(' ', t);
	}
	else
	{
		while (count-- > 0 && count >= 0 && count < 2147483647)
			ft_putchar_count(' ', t);
		ft_putstr_count(s, t);
	}
}

void	print_di(char *s, t_flags *t)
{
	int		count;
	int		len;
	char	sorz;

	sorz = ' ';
	len = ft_strlen(s);
	if (!t->minus && t->zero && t->prec <= len)
		sorz = '0';
	count = t->width;
	if (len < t->prec && t->prec != -1)
		count = count - t->prec;
	else if (t->width)
		count = count - len;
	if (t->plus || t->space)
		count--;
	after_dif(s, count, sorz, t);
}

void	after_dif(char *s, int c, char sorz, t_flags *t)
{
	if (t->minus && c > 0)
	{
		ft_putnumstr_dif(s, t);
		while (c-- > 0)
			ft_putchar_count(sorz, t);
	}
	else
	{
		if (t->plus && c > 0 && s[0] != '-' && t->prec == -1)
			ft_putchar_count('+', t);
		else if (t->space && c > 0 && s[0] != '-' && t->prec == -1)
			ft_putchar_count(' ', t);
		else if ((t->zero && c && s[0] == '-') || (t->prec > -1 && s[0] == '-'))
		{
			ft_putchar_count('-', t);
			s++;
			t->float_sign++;
			if (t->plus)
				c++;
		}
		while (c-- > 0 && c >= 0 && c < 2147483647)
			ft_putchar_count(sorz, t);
		ft_putnumstr_dif(s, t);
	}
}
