/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:36:16 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:36:23 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *rez;

	rez = dest;
	while (*dest)
		dest++;
	while (*src && n--)
		*(dest++) = *(src++);
	*dest = '\0';
	return (rez);
}
