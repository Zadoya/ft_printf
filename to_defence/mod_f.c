/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:23:02 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/04 19:23:05 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*float_to_str(union u_long_double	*a,
												t_specifications *data)
{
	unsigned long			mantissa;
	long int				exponent;
	char					*result;

	mantissa = a->s_parts_of_ld.m;
	exponent = a->s_parts_of_ld.e - 16383;
	result = divide_m(mantissa, data);
	if (exponent >= 0)
		result = multiplication(result, exponent);
	else
		result = division(result, -exponent, data);
	result = rounding(result, data);
	if (a->s_parts_of_ld.s)
		result = ft_concat_and_free("-", result);
	return (result);
}

int							mod_f(t_specifications *data, va_list *ap)
{
	int						result;
	union u_long_double		a;
	char					*str;

	if (data->sign[0] == 'f')
		a.ld = (long double)va_arg(*ap, double);
	else if (data->sign[0] == 'l')
		a.ld = (long double)va_arg(*ap, double);
	else if (data->sign[0] == 'L')
		a.ld = va_arg(*ap, long double);
	if (data->dot == 0)
		data->precision = 6;
	str = float_to_str(&a, data);
	print_float(&str, data);
	close_colour(data);
	result = ft_strlen(str);
	free(str);
	return (result);
}
