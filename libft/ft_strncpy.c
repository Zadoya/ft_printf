/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:36:55 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:36:56 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *rez;

	rez = dest;
	while (*src && len)
	{
		*(dest++) = *(src++);
		len--;
	}
	if (len)
		ft_bzero(dest, len);
	return (rez);
}
