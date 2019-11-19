/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:35:22 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:35:24 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;

	j = 0;
	i = 0;
	len_dest = ft_strlen(dest);
	while (dest[i] != '\0' && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (i < size - 1 && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (len_dest + ft_strlen(src));
}
