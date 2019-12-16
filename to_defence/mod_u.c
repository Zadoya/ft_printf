/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:42:03 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/26 17:42:05 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*in_case_of_long(char *str, t_specifications *data, va_list *ap)
{
	if (ft_strchr(data->sign, '%'))
	{
		str = malloc(2);
		str[1] = '\0';
		str[0] = '%';
		return (str);
	}
	data->ulnln = va_arg(*ap, unsigned long long);
	if (data->sign[0] == 'l' && data->sign[1] != 'l')
	{
		data->uln = data->ulnln;
		data->ulnln = data->uln;
	}
	str = ft_ulltoa_base(data->ulnln, 10);
	return (str);
}

static char		*in_case_of_sh(char *str, t_specifications *data, va_list *ap)
{
	if (ft_strchr(data->sign, '%'))
	{
		str = malloc(2);
		str[1] = '\0';
		str[0] = '%';
		return (str);
	}
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
	str = ft_itoa_base(data->in, 10);
	return (str);
}

int				mod_u(t_specifications *data, va_list *ap)
{
	int			result;
	char		*str;

	if (data->sign[0] == 'l' || data->sign[1] == 'l')
		str = in_case_of_long(str, data, ap);
	else
		str = in_case_of_sh(str, data, ap);
	if (data->flag[2] == '-')
		result = print_u_minus(&str, data);
	else
		result = print_u(&str, data);
	free(str);
	close_colour(data);
	return (result);
}
