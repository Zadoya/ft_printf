/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:35:59 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:36:02 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	unsigned int	i;

	if (s && (new = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (*s)
		{
			new[i++] = (*f)(*(s++));
		}
		return (new);
	}
	else
		return (NULL);
}
