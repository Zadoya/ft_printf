/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:00:18 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/28 16:00:22 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				parcer(char *str, va_list *arg_ptr)
{
	int					quantity;
	t_specifications	fmt;

	quantity = 0;
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			quantity++;
		}
		else
		{
			ft_bzero(fmt.flag, 6);
			ft_bzero(fmt.sign, 4);
			fmt.precision = 0;
			fmt.width = 0;
			fmt.dot = 0;
			str++;
			if (formated(&str, &fmt))
				quantity += find_function(&fmt, arg_ptr);
		}
		str++;
	}
	return (quantity);
}

int						ft_printf(const char *restrict format, ...)
{
	va_list				arg_ptr;
	char				*str;
	int					result;

	str = (char *)format;
	va_start(arg_ptr, format);
	result = parcer(str, &arg_ptr);
	va_end(arg_ptr);
	return (result);
}
