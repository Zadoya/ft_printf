/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:27:30 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:27:32 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	memory(int n, int *counter, char *znak)
{
	unsigned int tmp;

	if (n < 0)
	{
		(*znak)++;
		tmp = -n;
	}
	else
		tmp = n;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		(*counter)++;
	}
}

static char	*nbr(int n, int counter, char znak)
{
	char			*num;
	unsigned int	tmp;

	if (counter == 0)
		counter++;
	counter += znak;
	if (!(num = (char *)malloc(sizeof(char) * (counter + 1))))
		return (NULL);
	num[counter--] = '\0';
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	if (tmp == 0)
		num[counter] = '0';
	while (tmp > 0)
	{
		num[counter--] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (znak)
		num[0] = '-';
	return (num);
}

char		*ft_itoa(int n)
{
	int		counter;
	char	znak;

	znak = 0;
	counter = 0;
	memory(n, &counter, &znak);
	return (nbr(n, counter, znak));
}
