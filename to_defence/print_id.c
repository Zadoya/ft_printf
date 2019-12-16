/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:09:26 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/25 16:09:41 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*work_with_prcsn(char *str, t_specifications *data, char *tmp)
{
	int			len;
	char		*result;
	int			minus;

	minus = 0;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	len = ft_strlen(str);
	if (data->precision <= len && !minus)
		return (str);
	else if (data->precision <= len && minus)
		return (str - 1);
	tmp = malloc(data->precision + minus + 1);
	tmp[data->precision + minus] = '\0';
	result = tmp;
	if (minus)
		*(tmp++) = '-';
	while (data->precision > len++)
		*(tmp++) = '0';
	ft_strcpy(tmp, str);
	*(str - 1) == '-' ? free(str - 1) : free(str);
	return (result);
}

int				print_in_case_of_minus(char **str, t_specifications *data)
{
	int			result;
	char		*tmp;

	*str = work_with_prcsn(*str, data, tmp);
	result = ft_strlen(*str);
	if (**str != '-' && data->flag[3] == '+')
	{
		ft_putchar('+');
		result++;
	}
	if (**str != '-' && data->flag[4] == ' ' && data->flag[3] != '+')
	{
		ft_putchar(' ');
		result++;
	}
	ft_putstr(*str);
	while (data->width > result)
	{
		ft_putchar(' ');
		result++;
	}
	return (result);
}

static void		no_min_no_prcsn(char *str, t_specifications *data, int *result)
{
	if (data->width <= *result)
		ft_putstr(str);
	else
	{
		if (data->flag[1] == '0')
		{
			if (!ft_isdigit(*str))
				ft_putchar(*str);
			while (data->width > *result)
			{
				ft_putchar('0');
				(*result)++;
			}
			ft_isdigit(*str) == 0 ? ft_putstr(str + 1) : ft_putstr(str);
		}
		else
		{
			while (data->width > *result)
			{
				ft_putchar(' ');
				(*result)++;
			}
			ft_putstr(str);
		}
	}
}

int				print_without_minus(char **str, t_specifications *data)
{
	char		*tmp;
	int			result;

	*str = work_with_prcsn(*str, data, tmp);
	if (data->flag[3] == '+' && ft_isdigit(**str))
		*str = ft_concat_and_free("+", *str);
	else if (data->flag[4] == ' ' && data->flag[3] != '+' && ft_isdigit(**str))
		*str = ft_concat_and_free(" ", *str);
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
		no_min_no_prcsn(*str, data, &result);
	return (result);
}
