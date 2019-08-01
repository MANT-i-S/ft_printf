/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processors_csp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:37:51 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:47:04 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*begin(char *fmt, t_flags *t)
{
	while (*fmt)
	{
		if (*fmt != '%')
			ft_putchar_count(*fmt++, t);
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '%')
			{
				ft_putchar_count(*fmt, t);
				fmt++;
			}
			else if (*fmt && *fmt != '%')
			{
				detect_flags(fmt, t);
				while (*fmt && *fmt != t->specifier)
					fmt++;
				if (*fmt && *fmt == t->specifier)
					fmt++;
				break ;
			}
		}
	}
	return (fmt);
}

void	process_c(va_list ap, t_flags *t)
{
	int out;
	int count;

	count = t->width;
	out = va_arg(ap, int);
	if (t->minus && count >= 0 && count < 2147483647)
	{
		ft_putchar_count(out, t);
		while (count-- > 1)
			ft_putchar_count(' ', t);
	}
	else
	{
		while (count-- > 1 && count >= 0 && count < 2147483647)
			ft_putchar_count(' ', t);
		ft_putchar_count(out, t);
	}
}

void	process_s(va_list ap, t_flags *t)
{
	char *str;

	str = va_arg(ap, char *);
	if (str)
		print_s(str, t);
	else
	{
		str = "(null)";
		print_s(str, t);
	}
}

void	process_p(va_list ap, t_flags *t)
{
	unsigned long	p_to_p;
	char			*out;
	int				i;

	i = 0;
	out = ft_strnew(14);
	p_to_p = va_arg(ap, unsigned long);
	while (p_to_p)
	{
		if (p_to_p % 16 < 10)
			out[i++] = (p_to_p % 16) + 48;
		else
			out[i++] = (p_to_p % 16) - 10 + 97;
		p_to_p = p_to_p / 16;
	}
	ft_strrot(out);
	ft_putstr_count("0x", t);
	ft_putstr_count(out, t);
	ft_strdel(&out);
}

void	process_percent(char c, t_flags *t)
{
	int		count;
	char	sorz;

	sorz = ' ';
	count = t->width;
	if (!t->minus && t->zero)
		sorz = '0';
	if (t->minus && count >= 0 && count < 2147483647)
	{
		ft_putchar_count(c, t);
		while (count-- > 1)
			ft_putchar_count(sorz, t);
	}
	else
	{
		while (count-- > 1 && count >= 0 && count < 2147483647)
			ft_putchar_count(sorz, t);
		ft_putchar_count(c, t);
	}
}
