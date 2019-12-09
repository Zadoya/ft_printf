/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:25:52 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/09 13:25:56 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char 	*substraction(char *m, char *second_arg)
{
	int 		len_m;
	int 		len_second;

	len_m = ft_strlen(m);
	len_second = ft_strlen(second_arg);


}


char 			*divide_m(char *m, t_specifications *data)
{
	char 		result[data->precision + 22];
	int 		i;

	i = 0;
	result[i++] = '1';
	result[i++] = '.';
	m = substraction(m, "9223372036854775808");





	/*
	 * Этот код скорее всего бесполезен.
	 *
	 * if (ft_strlen(m) > 19)
		result[i++] = '1';
	else
	{
		if (ft_strcmp(m, "9223372036854775808") < 0)
			result[i++] = '0';
		else
			result[i++] = '1';
	}
	result[i++] = '.';*/
}
