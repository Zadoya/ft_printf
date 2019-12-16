/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:12:31 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/28 19:12:33 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			close_colour(t_specifications *data)
{
	if (data->colour == 'r' || data->colour == 'y' || data->colour == 'b')
	{
		ft_putstr("\x1b[0m");
		data->colour = 0;
	}
}

void			check_colour(t_specifications *data)
{
	if (data->colour == 'r')
		ft_putstr("\x1b[31m");
	else if (data->colour == 'y')
		ft_putstr("\x1b[32m");
	else if (data->colour == 'b')
		ft_putstr("\x1b[34m");
}
