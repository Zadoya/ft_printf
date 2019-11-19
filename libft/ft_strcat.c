/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:33:20 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:33:22 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *rez;

	rez = dest;
	while (*dest)
		dest++;
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (rez);
}
