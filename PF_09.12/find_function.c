/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:46:43 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/20 12:46:46 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_function(t_specifications *data, va_list *ap)
{
	check_colour(data);
	if (ft_strchr(data->sign, 'c'))
		return (mod_c(data, ap));
	else if (ft_strchr(data->sign, 's'))
		return (mod_s(data, ap));
	else if (ft_strchr(data->sign, 'p'))
		return (mod_p(data, ap));
	else if (ft_strchr(data->sign, 'i') || ft_strchr(data->sign, 'd'))
		return (mod_id(data, ap));
	else if (ft_strchr(data->sign, 'u'))
		return (mod_u(data, ap));
	else if (ft_strchr(data->sign, 'o'))
		return (mod_o(data, ap));
	else if (ft_strchr(data->sign, 'x') || ft_strchr(data->sign, 'X'))
		return (mod_x(data, ap));
	else if (ft_strchr(data->sign, '%'))
		return (mod_u(data, ap));
	else if (ft_strchr(data->sign, 'S'))
		return (mod_ss(data, ap));
	else if (ft_strchr(data->sign, 'B'))
		return (mod_b(data, ap));
	else if (ft_strchr(data->sign, 'T'))
		return (mod_file(data, ap));
	else if (ft_strchr(data->sign, 'f'))
		return (mod_f(data, ap));
	return (0);

	/*
	else if (ft_strchr(data->sign, 'f'))
		return (mod_f(data, ap));
	*/
}
