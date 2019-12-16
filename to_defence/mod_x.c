/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:42:56 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/27 14:42:59 by dorphan          ###   ########.fr       */
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
	str = ft_ulltoa_base(data->ulnln, 16);
	return (str);
}

static char		*in_case_of_sh(char *str, t_specifications *data, va_list *ap)
{
	data->uin = va_arg(*ap, unsigned int);
	if (data->sign[0] == 'h' && data->sign[1] != 'h')
	{
		data->ush = data->uin;
		data->uin = data->ush;
	}
	else if (data->sign[0] == 'h' && data->sign[1] == 'h')
	{
		data->uch = data->uin;
		data->uin = data->uch;
	}
	str = ft_ulltoa_base(data->uin, 16);
	return (str);
}

int				mod_x(t_specifications *data, va_list *ap)
{
	int			result;
	char		*str;
	char		*tmp;

	if (data->sign[0] == 'l' || data->sign[1] == 'l')
		str = in_case_of_long(str, data, ap);
	else
		str = in_case_of_sh(str, data, ap);
	if (data->flag[2] == '-')
		result = print_x_minus(&str, data);
	else
		result = print_x(&str, data);
	free(str);
	close_colour(data);
	return (result);
}
