/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:51:24 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/20 12:51:27 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_in_case_of_min(char *str, t_specifications *data)
{
	char		*tmp;

	tmp = str;
	if (data->dot == 0)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else
	{
		while (*tmp && tmp - str < data->precision)
			ft_putchar(*(tmp++));
		return ((int)(tmp - str));
	}
}

static int		print(t_specifications *data, char *str)
{
	int			len;
	char		*copy;
	int			result;

	copy = ft_strdup(str);
	len = ft_strlen(copy);
	if (data->dot == 1 && data->precision < len && data->precision >= 0)
		copy[data->precision] = '\0';
	len = ft_strlen(copy);
	if (data->width > len)
	{
		result = data->width;
		while (data->width-- != len)
			ft_putchar(' ');
	}
	else
		result = len;
	ft_putstr(copy);
	free(copy);
	return (result);
}

int				mod_s(t_specifications *data, va_list *ap)
{
	char		*str;
	int			result;
	int			len;

	str = va_arg(*ap, char *);
	len = ft_strlen(str);
	if (data->flag[2] == '-')
	{
		result = print_in_case_of_min(str, data);
		while (data->width > result)
		{
			ft_putchar(' ');
			result++;
		}
	}
	else
		result = print(data, str);
	close_colour(data);
	return (result);
}
