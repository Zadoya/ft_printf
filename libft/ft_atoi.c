/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:24:39 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:24:43 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digits(const char *str, long long number, int i, int znak)
{
	i = ft_front_whitespaces(str, i);
	if ((str[i] == '+') && (str[i + 1] >= '0') && (str[i + 1] <= '9'))
		i++;
	else if ((str[i] == '-') && (str[i + 1] >= '0') && (str[i + 1] <= '9'))
	{
		i++;
		znak = -1;
	}
	else if ((str[i + 1] < '0') && (str[i + 1] > '9'))
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if ((number * 10 + (str[i] - '0')) < number && znak == 1)
			return (-1);
		else if ((number * 10 + (str[i] - '0')) < number && znak == -1)
			return (1);
		number = 10 * number + (str[i] - '0');
		i++;
	}
	return (number * znak);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			znak;
	long long	number;

	number = 0;
	znak = 1;
	i = 0;
	return (digits(str, number, i, znak));
}
