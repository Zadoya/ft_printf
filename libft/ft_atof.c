/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:24:39 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:24:43 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	is_too_much(double res, char znak)
{
	if (res > __DBL_MAX__ && znak == 1)
		return (__builtin_huge_valf());
	else if (res > __DBL_MAX__ && znak == -1)
		return (-__builtin_huge_valf());
	else
		return (res * (double)znak);
}

static double	fraction(const char *str, size_t *i)
{
	double fract;

	fract = 0;
	(*i)++;
	if ((str[*i] >= '0') && (str[*i] <= '9'))
		fract = (double)(str[*i] - '0') / 10.0 + fraction(str, i) / 10.0;
	return (fract);
}

static double	power(double number, const char *str, int i)
{
	int power;

	power = 0;
	if (!ft_strncmp(&str[i], "e-", 2))
	{
		power = ft_atoi(&str[i + 2]);
		while (power--)
			number = number / 10;
	}
	else if (!ft_strncmp(&str[i], "e+", 2))
	{
		power = ft_atoi(&str[i + 2]);
		while (power--)
			number = number * 10;
	}
	return (number);
}

static double	num(const char *str, double number, size_t i, char znak)
{
	i = ft_front_whitespaces(str, i);
	if (!ft_strncmp(ft_strlowcase(str), "-inf", 4))
		return (-__builtin_huge_valf());
	if (!ft_strncmp(ft_strlowcase(str), "inf", 3))
		return (__builtin_huge_valf());
	if (!ft_strncmp(ft_strlowcase(str), "nan", 3))
		return (__builtin_nanf("0x7fc00000"));
	if ((str[i] == '+' || str[i] == '-') && ((str[i + 1] >= '0' &&
		str[i + 1] <= '9') || str[i + 1] == '.'))
	{
		if (str[i] == '-')
			znak = -1;
		i++;
	}
	else if (((str[i] < '0') && (str[i] > '9')) && str[i] != '.')
		return (0);
	while (str[i] != '.' && str[i] >= '0' && str[i] <= '9')
		number = 10 * number + (str[i++] - '0');
	if (str[i] == '.')
		number = (number + fraction(str, &i));
	number = power(number, str, i);
	return (is_too_much(number, znak));
}

double			ft_atof(const char *str)
{
	size_t	i;
	char	znak;
	double	number;

	number = 0;
	znak = 1;
	i = 0;
	if (!str)
		return (0);
	return (num(str, number, i, znak));
}
