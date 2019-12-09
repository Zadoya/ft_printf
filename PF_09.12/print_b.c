/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:33:48 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/29 13:33:50 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*work_with_prcsn(char *str, t_specifications *data, char *tmp)
{
	int			len;
	char		*result;

	len = ft_strlen(str);
	if (data->precision <= len)
		return (str);
	tmp = malloc(data->precision + 1);
	tmp[data->precision] = '\0';
	result = tmp;
	while (data->precision > len++)
		*(tmp++) = '0';
	ft_strcpy(tmp, str);
	free(str);
	return (result);
}

static void		no_prcsn(char *str, t_specifications *data, int *result)
{
	char		*tmp;

	tmp = str;
	if (data->width <= *result)
		ft_putstr(str);
	else
	{
		while (data->width > *result)
		{
			data->flag[1] == '0' ? ft_putchar('0') : ft_putchar(' ');
			(*result)++;
		}
		ft_putstr(tmp);
	}
}

int				print_b_minus(char **str, t_specifications *data)
{
	int			result;
	char		*tmp;

	*str = work_with_prcsn(*str, data, tmp);
	result = ft_strlen(*str);
	ft_putstr(*str);
	while (data->width > result)
	{
		ft_putchar(' ');
		result++;
	}
	return (result);
}

int				print_b(char **str, t_specifications *data)
{
	char		*tmp;
	int			result;

	*str = work_with_prcsn(*str, data, tmp);
	result = ft_strlen(*str);
	if (data->dot)
	{
		while (data->width > result)
		{
			ft_putchar(' ');
			result++;
		}
		ft_putstr(*str);
	}
	else
		no_prcsn(*str, data, &result);
	return (result);
}
