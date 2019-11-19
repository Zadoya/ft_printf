/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:39:14 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:39:16 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s)
		return (NULL);
	if ((start + len > ft_strlen(s)) || !s)
		return (NULL);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	while (len--)
		sub[len] = s[start + len];
	return (sub);
}
