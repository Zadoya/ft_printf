/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:53:41 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/29 13:53:44 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 		mod_file(t_specifications *data, va_list *ap)
{
	char		*str;
	int			result;
	int			fd;

	str = va_arg(*ap, char *);
	fd = open(str, O_RDONLY);
	result = ft_print_file(fd);
	close_colour(data);
	close(fd);
	return (result);
}
