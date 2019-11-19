/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:36:07 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:36:08 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (s && (new = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (*s)
		{
			new[i] = (*f)(i, *(s++));
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
