/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:56:45 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/27 12:56:47 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc(unsigned long long num, unsigned long long base)
{
	int			result;

	result = 1;
	while (num >= base)
	{
		num /= base;
		result++;
	}
	return (result);
}

static void		trnsfm(char *result, unsigned long long num,
							unsigned long long base, int size)
{
	char		*arr;

	arr = "0123456789abcdef";
	if (base <= 10)
	{
		if (num >= base)
			trnsfm(result, num / base, base, size - 1);
		result[size] = num % base + '0';
	}
	else
	{
		if (num >= base)
			trnsfm(result, num / base, base, size - 1);
		result[size] = arr[num % base];
	}
}

char			*ft_ulltoa_base(unsigned long long num, unsigned long long base)
{
	char		*result;
	int			size;
	char		*tmp;

	size = calc(num, base);
	if (!(result = malloc(size + 1)))
		return (NULL);
	result[size] = '\0';
	tmp = result;
	trnsfm(tmp, num, base, size - 1);
	return (result);
}
