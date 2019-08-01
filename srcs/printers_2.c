/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:53:28 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:52:27 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnumstr_dif(char const *str, t_flags *t)
{
	int	len[2];

	len[0] = ft_strlen(str);
	len[1] = t->prec - len[0];
	if (len > 0)
	{
		if (t->plus && str[0] != '-' && !t->zero)
			ft_putchar_count('+', t);
		else if (t->space && str[0] != '-' && !t->zero)
			ft_putchar_count(' ', t);
		if (t->float_sign && len[0] == 1)
			len[1]--;
		while (len[1]-- > 0 && len[0] > 0 && len[0] < t->prec)
			ft_putchar_count('0', t);
		if (!t->minus && t->zero && t->width > len[0] && str[0] == '-')
			str++;
		if (!t->minus && t->zero && t->width > len[0] && str[0] == '-')
			len[0]--;
		write(1, str, len[0]);
		if (t->hash && t->specifier == 'f' && t->prec == 0)
			ft_putchar_count('.', t);
		if (t->float_zeros)
			ft_putstr_count("00000", t);
		t->glob_count = t->glob_count + len[0];
	}
}

void	ft_putnumstr_uoxx(char const *str, t_flags *t)
{
	int	len;
	int	count;

	len = ft_strlen(str);
	count = t->prec - len;
	if (len >= 0)
	{
		if (t->hash && t->specifier == 'o')
			ft_putchar_count('0', t);
		if (t->hash && t->specifier == 'x' &&
		str[0] != '0' && !t->zero && len > 0)
			ft_putstr_count("0x", t);
		if (t->hash && t->specifier == 'X' &&
		str[0] != '0' && !t->zero && len > 0)
			ft_putstr_count("0X", t);
		while (count-- > 0 && len > 0 && len < t->prec)
		{
			ft_putchar_count('0', t);
		}
		write(1, str, len);
		t->glob_count = t->glob_count + len;
	}
}

void	print_uoxx(char *str, t_flags *t)
{
	int		count;
	int		len;
	char	sorz;

	sorz = ' ';
	if (t->zero && t->prec == -1 && !t->minus)
		sorz = '0';
	len = ft_strlen(str);
	count = t->width;
	if (t->hash && t->specifier == 'o')
		count--;
	if (t->hash && (t->specifier == 'x' || t->specifier == 'X'))
		count = count - 2;
	if (len < t->prec && t->prec != -1)
		count = count - t->prec;
	else if (t->width)
		count = count - len;
	if (t->hash && t->specifier == 'x' && str[0] != '0' && t->zero)
		ft_putstr_count("0x", t);
	if (t->hash && t->specifier == 'X' && str[0] != '0' && t->zero)
		ft_putstr_count("0X", t);
	after_uoxx(str, count, sorz, t);
}

void	after_uoxx(char *str, int count, char sorz, t_flags *t)
{
	if (t->minus && count > 0)
	{
		ft_putnumstr_uoxx(str, t);
		while (count-- > 0)
			ft_putchar_count(sorz, t);
	}
	else
	{
		while (count-- > 0 && count >= 0 && count < 2147483647)
			ft_putchar_count(sorz, t);
		ft_putnumstr_uoxx(str, t);
	}
}

void	print_f(char *str, t_flags *t)
{
	int		count;
	int		len;
	char	sorz;

	sorz = ' ';
	if (t->zero && t->prec == -1)
		sorz = '0';
	len = ft_strlen(str);
	count = t->width;
	if (len < t->prec && t->prec != -1)
		count = count - t->prec;
	else if (t->width)
		count = count - len;
	if (t->plus || t->space)
		count--;
	if (t->hash && t->prec == 0)
		count--;
	after_dif(str, count, sorz, t);
}
