/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:40:19 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/29 14:40:22 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "libft.h"

int			ft_print_file(int fd)
{
	char	buf[33];
	int		result;
	int		ret;

	result = 0;
	while ((ret = read(fd, buf, 32)))
	{
		if (ret < 0)
			return (0);
		buf[ret] = '\0';
		result += ret;
		ft_putstr(buf);
	}
	return (result);
}
