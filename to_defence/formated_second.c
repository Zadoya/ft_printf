/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formated_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:58:11 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/28 15:58:13 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_colour(t_specifications *fmt, char c)
{
	if (c == 'r')
		fmt->colour = 'r';
	else if (c == 'y')
		fmt->colour = 'y';
	else if (c == 'b')
		fmt->colour = 'b';
}

int		in_case_of_dot(int *dot, t_specifications *fmt)
{
	if (*dot == 0)
	{
		fmt->dot = 1;
		(*dot)++;
		return (0);
	}
	else
		return (1);
}
