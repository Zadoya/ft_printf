/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:33:40 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/13 15:33:42 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int			modifyer(char **p, va_list *ap)
{
	int		result;

	result = 0;
	if (*((*p) + 1) == '%')
	{
		ft_putchar(**p);
		*p = *p + 2;
		result++;
	}
	else if (*((*p) + 1) == 'c' || *((*p) + 1) == 's' || *((*p) + 1) == 'p'
				|| *((*p) + 1) == 'd' || *((*p) + 1) == 'i' ||
				*((*p) + 1) == 'o' || *((*p) + 1) == 'u' ||
				*((*p) + 1) == 'x' || *((*p) + 1) == 'X' || *((*p) + 1) == 'f')
	{
		result = modifyers(p, ap);
		*p = *p + 2;
	}
	return (result);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	char	*p;
	int		result;

	p = (char *)format;
	result = 0;
	va_start(ap, format);
	while (*p)
	{
		if (*p == '%')
			result = result + modifyer(&p, &ap);
		else
		{
			ft_putchar(*p);
			result++;
			p++;
		}
	}
	return (result);
}
*/