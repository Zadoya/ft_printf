/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:13:37 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/19 15:13:40 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_function(t_specifications *data, va_list *ap)
{
	int		(*mod[16])(t_specifications *, va_list *);//= {di, di, o, x, x, u, c, s, f, e, e, g, g, p, n, %};
	char	*type;
	
	mod[6] = c;
	mod[8] = f;
	type = data->sign;
	while(type)
		if (*type == 'h' ||  *type == 'l')
			type++;
		else 
			return (mod[ft_istype(*type)](data, ap));
	return(0);
}