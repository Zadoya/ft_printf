/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:29:54 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:29:56 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *tmp;

	tmp = s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}
