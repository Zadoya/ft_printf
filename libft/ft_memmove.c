/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:30:46 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:30:48 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	i = 0;
	if (tmp_src < tmp_dst)
		while (++i <= len)
			tmp_dst[len - i] = tmp_src[len - i];
	else
		while (len-- > 0)
			*(tmp_dst++) = *(tmp_src++);
	return (dst);
}
