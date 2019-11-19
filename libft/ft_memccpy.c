/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:29:39 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:29:41 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp_dst;
	const unsigned char *tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	while (n--)
	{
		*(tmp_dst++) = *(tmp_src);
		if ((unsigned char)c == *(tmp_src++))
		{
			return (tmp_dst);
		}
	}
	return (NULL);
}
