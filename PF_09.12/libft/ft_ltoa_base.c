/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:16:16 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/15 13:16:19 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc(long long num, int base)
{
	int			result;

	result = 1;
	if (num < 0)
	{
		num *= -1;
		result++;
	}
	while (num >= base)
	{
		num /= base;
		result++;
	}
	return (result);
}

static void		transformator(char *result, long long num, int base, int size)
{
	char		*arr;

	arr = "0123456789abcdef";
	if (base <= 10)
	{
		if (num >= base)
			transformator(result, num / base, base, size - 1);
		result[size] = num % base + '0';
	}
	else
	{
		if (num >= base)
			transformator(result, num / base, base, size - 1);
		result[size] = arr[num % base];
	}
}

char			*ft_ltoa_base(long long num, int base)
{
	char		*result;
	int			size;
	char		*tmp;

	size = calc(num, base);
	if (!(result = malloc(size + 1)))
		return (NULL);
	result[size] = '\0';
	tmp = result;
	if (num < 0)
	{
		*tmp = '-';
		num *= -1;
		tmp++;
		size--;
	}
	transformator(tmp, num, base, size - 1);
	return (result);
}
