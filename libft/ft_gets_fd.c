/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:30:31 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 22:35:34 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_gets_fd(int fd, char **str, size_t len)
{
	int		c;
	size_t	i;

	i = 0;
	if (!(*str = ft_strnew(len)))
		return (-1);
	while ((c = ft_getc_fd(fd)) != '\n' && c && c != -1
			&& (i < sizeof(*str) || i < len))
		(*str)[i++] = (char)c;
	if (c == 0)
		(*str)[i] = '\0';
	else if (c == -1)
	{
		free(*str);
		*str = NULL;
	}
	return (c);
}
