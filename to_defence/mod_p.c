/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:17:07 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/22 16:17:09 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_in_case_of_min(char *str, t_specifications *data)
{
	int				spases;

	spases = data->width - ft_strlen(str) - 2;
	ft_putstr("0x");
	ft_putstr(str);
	while (spases-- > 0)
		ft_putchar(' ');
}

static void			print_without_min(char *str, t_specifications *data)
{
	int				spases;

	spases = data->width - ft_strlen(str) - 2;
	while (spases-- > 0)
		ft_putchar(' ');
	ft_putstr("0x");
	ft_putstr(str);
}

int					mod_p(t_specifications *data, va_list *ap)
{
	unsigned long	p;
	int				result;
	char			*str;

	if (data->width > 11)
		result = data->width;
	else
		result = 11;
	p = va_arg(*ap, unsigned long);
	str = ft_ltoa_base((long long)p, 16);
	if (data->flag[2] == '-')
		print_in_case_of_min(str, data);
	else
		print_without_min(str, data);
	free(str);
	close_colour(data);
	return (result);
}
