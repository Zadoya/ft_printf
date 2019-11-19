/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:53:05 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/09 14:57:31 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(const char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_strnew(ft_strlen(str))))
		return (NULL);
	tmp = ft_strcpy(tmp, str);
	if (tmp)
		while (tmp[i])
		{
			tmp[i] = ft_tolower(tmp[i]);
			i++;
		}
	return (tmp);
}
