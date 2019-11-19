/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:13:02 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/14 14:13:04 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int			mod_x(t_specifications *data, va_list *ap)
{
	int 	x;
	int 	result;
	char 	*str;
	char	*tmp;

	x = va_arg(*ap, int);
	str = ft_itoa_base(x, 16);
	tmp = str;
	result = ft_strlen(str);
	if (c == 'X')
		while (*(tmp++))
			if (*tmp >= 'a' && *tmp <= 'f')
				*tmp -= 32;
	ft_putstr(str);
	free(str);
	return (result);
}

int			mod_o(t_specifications *data, va_list *ap)
{
	int 	o;
	int 	result;
	char 	*str;

	o = va_arg(*ap, int);
	str = ft_itoa_base(o, 8);
	result = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (result);
}

int			mod_id(t_specifications *data, va_list *ap)
{
	int		i;
	int 	result;

	result = 1;
	i = va_arg(*ap, int);
	ft_putnbr(i);
	if (i < 0)
	{
		result++;
		i *= -1;
	}
	while (i > 9)
	{
		i /= 10;
		result++;
	}
	return (result);
}

int			mod_s(t_specifications *data, va_list *ap)
{
	char 	*str;
	char	*tmp;

	str = va_arg(*ap,char *);
	tmp = str;
	while (*tmp)
		write(1, tmp++, 1);
	return (tmp - str);
}
*/
/*
int			mod_c(t_specifications *data, va_list *ap)
{
	char 	c;
	int 	result;

	if (data->width > 1)
		result = data->width;
	else
		result = 1;
	c = va_arg(*ap, int);
	if (data->flag[2] == '-')
	{
		ft_putchar(c);
		while ((data->width)-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while ((data->width)-- > 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (result);
}
*/