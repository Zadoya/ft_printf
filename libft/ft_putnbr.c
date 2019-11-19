/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:31:53 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:31:55 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int number;

	if (n < 0)
	{
		ft_putchar('-');
		number = (unsigned int)(-n);
	}
	else
	{
		number = (unsigned int)n;
	}
	if (number >= 10)
		ft_putnbr(number / 10);
	ft_putchar((char)(number % 10 + '0'));
}
