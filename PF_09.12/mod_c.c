/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:35:51 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/20 12:36:02 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			mod_c(t_specifications *data, va_list *ap)
{
	char	c;
	int		result;

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
	close_colour(data);
	return (result);
}
