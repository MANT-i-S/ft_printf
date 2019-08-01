/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:33:26 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/31 15:24:05 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include <limits.h>

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			prec;
	char		length1;
	char		length2;
	char		specifier;
	int			glob_count;
	int			float_sign;
	int			float_zeros;
}				t_flags;

int				ft_printf(const char *fmt, ...);
char			*begin(char *fmt, t_flags *t);
void			detect_flags(char *fmt, t_flags *t);
void			detect_width(char *fmt, t_flags *t);
void			detect_precision(char *fmt, t_flags *t);
void			detect_length(char *fmt, t_flags *t);
void			detect_specifier(char *fmt, t_flags *t);
void			dispatch(va_list ap, t_flags *t);
void			ft_putchar_count(char c, t_flags *t);
void			ft_putstr_count(char const *s, t_flags *t);
void			ft_putnumstr_dif(char const *str, t_flags *t);
void			ft_putnumstr_uoxx(char const *str, t_flags *t);
void			print_s(char *str, t_flags *t);
void			print_di(char *str, t_flags *t);
void			print_uoxx(char *str, t_flags *t);
void			print_f(char *str, t_flags *t);
void			after_dif(char *str, int count, char sorz, t_flags *t);
void			after_uoxx(char *str, int count, char sorz, t_flags *t);
intmax_t		cast_int(va_list ap, t_flags *t);
uintmax_t		cast_uns_int(va_list ap, t_flags *t);
char			*ultra_itoa(intmax_t n);
char			*ultra_itoarev(intmax_t n, char *dest);
char			*u_ultra_itoa(uintmax_t n);
char			*u_ultra_itoarev(uintmax_t n, char *dest);
int				itos(unsigned long long x, char str[], int d, t_flags *t);
char			*double_itoa(double n, char *res, t_flags *t);
char			*long_double_itoa(long double n, char *res, t_flags *t);
void			process_percent(char c, t_flags *t);
void			process_c(va_list ap, t_flags *t);
void			process_s(va_list ap, t_flags *t);
void			process_p(va_list ap, t_flags *t);
void			process_d(va_list ap, t_flags *t);
void			process_i(va_list ap, t_flags *t);
void			process_u(va_list ap, t_flags *t);
void			process_o(va_list ap, t_flags *t);
void			process_x(va_list ap, t_flags *t);
void			process_xx(va_list ap, t_flags *t);
void			process_f(va_list ap, t_flags *t);

#endif
