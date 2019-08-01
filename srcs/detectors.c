/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:33:35 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:59:10 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	detect_flags(char *fmt, t_flags *t)
{
	while (*fmt && (*fmt == '#' || *fmt == '0' ||
	*fmt == '-' || *fmt == '+' || *fmt == ' '))
	{
		if (*fmt == '#' && t->hash == 0)
			t->hash = 1;
		if (*fmt == '0' && t->zero == 0)
			t->zero = 1;
		if (*fmt == '-' && t->minus == 0)
			t->minus = 1;
		if (*fmt == '+' && t->plus == 0)
			t->plus = 1;
		if (*fmt == ' ' && t->space == 0)
			t->space = 1;
		fmt++;
	}
	detect_width(fmt, t);
}

void	detect_width(char *fmt, t_flags *t)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(10);
	while (*fmt && i < 11 && *fmt >= '0' && *fmt <= '9')
	{
		str[i] = *fmt;
		fmt++;
		i++;
	}
	t->width = ft_atoi(str);
	ft_strdel(&str);
	detect_precision(fmt, t);
}

void	detect_precision(char *fmt, t_flags *t)
{
	char	*str;
	int		i;

	i = 0;
	t->prec = -1;
	str = ft_strnew(10);
	if (*fmt == '.')
	{
		fmt++;
		while (*fmt && i < 11 && *fmt >= '0' && *fmt <= '9')
		{
			str[i] = *fmt;
			fmt++;
			i++;
		}
		t->prec = ft_atoi(str);
	}
	ft_strdel(&str);
	detect_length(fmt, t);
}

void	detect_length(char *fmt, t_flags *t)
{
	while (*fmt && (*fmt == 'h' || *fmt == 'l' || *fmt == 'L'))
	{
		if (((*fmt == 'h' && t->length1 != 'h')
		|| (*fmt == 'l' && t->length1 != 'l')
		|| (*fmt == 'L' && t->length1 != 'L')))
		{
			t->length1 = *fmt;
			fmt++;
		}
		else if ((*fmt == 'h' && t->length1 == 'h')
		|| (*fmt == 'l' && t->length1 == 'l'))
		{
			t->length2 = *fmt;
			fmt++;
		}
		else
			fmt++;
	}
	detect_specifier(fmt, t);
}

void	detect_specifier(char *fmt, t_flags *t)
{
	char *str;

	str = "cspdiuoxXf";
	while (*fmt && *str && *fmt != *str)
		str++;
	if (*fmt == *str)
	{
		t->specifier = *fmt;
		fmt++;
	}
	if (*fmt == '%' && !t->specifier)
		process_percent('%', t);
}
