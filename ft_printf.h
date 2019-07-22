/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:33:26 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/22 16:24:49 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H_ 
#define FT_PRINTF_H_

#include "libft.h"
#include <stdarg.h>

typedef struct			s_flags
{
	int					hash;
	int					zero;
	int					minus;
	int					plus;
	int					space;
	int					width; //Not higher then 2147483646
	int					precision; //Should be -1 by default, Not higher then 2147483646.
	char				length1; //Might be couple of chars.
	char				length2;
	char				specifier;
}						t_flags;

int			ft_printf(const char *fmt, ...);
void		begin(char *fmt, t_flags *table);
void		detect_flags(char *fmt, t_flags *table);
void		detect_width(char *fmt, t_flags *table);
void		detect_precision(char *fmt, t_flags *table);
void		detect_length(char *fmt, t_flags *table);
void		detect_specifier(char *fmt, t_flags *table);
int			dispatch(va_list ap, t_flags *table);
typedef int	determine(va_list ap, t_flags *table);
int			process_c(va_list ap, t_flags *table);
// int			process_s(va_list ap, t_flags *table);
// int			process_p(va_list ap, t_flags *table);
// int			process_d(va_list ap, t_flags *table);
// int			process_i(va_list ap, t_flags *table);
// int			process_o(va_list ap, t_flags *table);
// int			process_u(va_list ap, t_flags *table);
// int			process_x(va_list ap, t_flags *table);
// int			process_X(va_list ap, t_flags *table);
// int			process_f(va_list ap, t_flags *table);

#endif