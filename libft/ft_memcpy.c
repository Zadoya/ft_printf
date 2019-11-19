/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:30:22 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:30:23 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_dst;
	const unsigned char *tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = dst;
	tmp_src = src;
	while (n--)
		*(tmp_dst++) = *(tmp_src++);
	return (dst);
}
