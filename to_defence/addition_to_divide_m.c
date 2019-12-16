/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_to_divide_m.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:29:21 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/16 11:29:23 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		addition_to_divide_m(char **m, char **result, int *i)
{
	while (ft_strlen(*m) < 19)
	{
		*m = ft_concat_and_freehead(*m, "0");
		*result[(*i)++] = '0';
	}
	if (ft_strlen(*m) == 19 && ft_strcmp(*m, "9223372036854775808") < 0)
	{
		*m = ft_concat_and_freehead(*m, "0");
		*result[(*i)++] = '0';
	}
}
