/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:29:54 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/29 13:29:57 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*in_case_of_long(char *str, t_specifications *data, va_list *ap)
{
	data->ulnln = va_arg(*ap, unsigned long long);
	if (data->sign[0] == 'l' && data->sign[1] != 'l')
	{
		data->uln = data->ulnln;
		data->ulnln = data->uln;
	}
	str = ft_ulltoa_base(data->ulnln, 2);
	return (str);
}

static char		*in_case_of_sh(char *str, t_specifications *data, va_list *ap)
{
	data->in = va_arg(*ap, int);
	if (data->sign[0] == 'h' && data->sign[1] != 'h')
	{
		data->ush = data->in;
		data->in = data->ush;
	}
	else if (data->sign[0] == 'h' && data->sign[1] == 'h')
	{
		data->uch = data->in;
		data->in = data->uch;
	}
	str = ft_itoa_base(data->in, 2);
	return (str);
}

int				mod_b(t_specifications *data, va_list *ap)
{
	int			result;
	char		*str;
	char		*tmp;

	if (data->sign[0] == 'l' || data->sign[1] == 'l')
		str = in_case_of_long(str, data, ap);
	else
		str = in_case_of_sh(str, data, ap);
	if (data->flag[2] == '-')
		result = print_b_minus(&str, data);
	else
		result = print_b(&str, data);
	free(str);
	close_colour(data);
	return (result);
}
