/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:45:13 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/22 16:45:15 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*in_case_of_long(char *str, t_specifications *data, va_list *ap)
{
	long long	i;

	i = va_arg(*ap, long long);
	if (data->sign[0] == 'l' && data->sign[1] != 'l')
	{
		data->ln = i;
		i = data->ln;
	}
	str = ft_ltoa_base(i, 10);
	return (str);
}

static char		*in_case_of_sh(char *str, t_specifications *data, va_list *ap)
{
	data->in = va_arg(*ap, int);
	if (data->sign[0] == 'h' && data->sign[1] != 'h')
	{
		data->sh = data->in;
		data->in = data->sh;
	}
	else if (data->sign[0] == 'h' && data->sign[1] == 'h')
	{
		data->ch = data->in;
		data->in = data->ch;
	}
	str = ft_itoa_base(data->in, 10);
	return (str);
}

int				mod_id(t_specifications *data, va_list *ap)
{
	int			result;
	char		*str;

	if (data->sign[0] == 'l' || data->sign[1] == 'l')
		str = in_case_of_long(str, data, ap);
	else
		str = in_case_of_sh(str, data, ap);
	if (data->flag[2] == '-')
		result = print_in_case_of_minus(&str, data);
	else
		result = print_without_minus(&str, data);
	free(str);
	close_colour(data);
	return (result);
}
