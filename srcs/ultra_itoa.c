/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:10:21 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 13:27:36 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ultra_itoa(intmax_t n)
{
	char	*dest;

	dest = ft_strnew(ft_intcount(n));
	if (!dest)
		return (NULL);
	dest = ultra_itoarev(n, dest);
	dest = ft_strrot(dest);
	return (dest);
}

char	*ultra_itoarev(intmax_t n, char *dest)
{
	intmax_t	i;
	int			mod;
	int			sign;

	i = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	while (n >= 10)
	{
		mod = n % 10;
		n = n / 10;
		dest[i++] = mod + 48;
	}
	dest[i++] = n + 48;
	if (sign == 1)
		dest[i++] = '-';
	dest[i] = '\0';
	return (dest);
}

char	*u_ultra_itoa(uintmax_t n)
{
	char	*dest;

	dest = ft_strnew(ft_intcount(n));
	if (!dest)
		return (NULL);
	dest = u_ultra_itoarev(n, dest);
	dest = ft_strrot(dest);
	return (dest);
}

char	*u_ultra_itoarev(uintmax_t n, char *dest)
{
	uintmax_t	i;
	int			mod;

	i = 0;
	while (n >= 10)
	{
		mod = n % 10;
		n = n / 10;
		dest[i++] = mod + 48;
	}
	dest[i++] = n + 48;
	dest[i] = '\0';
	return (dest);
}
