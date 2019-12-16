/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:11:43 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/15 14:11:48 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*in_case_of_minus(char *str, t_specifications *data)
{
	if (data->width <= ft_strlen(str))
		return (str);
	while (ft_strlen(str) < data->width)
		str = ft_concat_and_freehead(str, " ");
	return (str);
}

static char		*no_minus(char *str, t_specifications *data)
{
	char		*tmp;
	int			sign_indicator;

	sign_indicator = 0;
	if (!ft_isdigit(*str))
		sign_indicator = 1;
	if (data->width <= ft_strlen(str))
		return (str);
	if (data->flag[1] == '0')
	{
		while (ft_strlen(str) < data->width)
			str = ft_concat_and_free("0", str);
		if (sign_indicator)
		{
			tmp = str;
			while (*tmp == '0')
				tmp++;
			ft_swap(tmp, str);
		}
	}
	else
		while (ft_strlen(str) < data->width)
			str = ft_concat_and_free(" ", str);
	return (str);
}

void			print_float(char **str, t_specifications *data)
{
	int			len;
	char		*tmp;

	tmp = *str;
	while (*tmp != '.')
		tmp++;
	tmp++;
	while (data->precision)
	{
		tmp++;
		data->precision--;
	}
	tmp = ft_strsub(*str, 0, tmp - *str);
	free(*str);
	*str = tmp;
	if (data->flag[3] == '+' && ft_isdigit(**str))
		*str = ft_concat_and_free("+", *str);
	else if (data->flag[4] == ' ' && data->flag[3] != '+' && ft_isdigit(**str))
		*str = ft_concat_and_free(" ", *str);
	if (data->flag[2] == '-')
		*str = in_case_of_minus(*str, data);
	else
		*str = no_minus(*str, data);
	ft_putstr(*str);
}
