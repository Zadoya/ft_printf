/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:35:14 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:35:15 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (!s1 || !s2 || !(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (*s1)
		new[i++] = *(s1++);
	while (*s2)
		new[i++] = *(s2++);
	return (new);
}
