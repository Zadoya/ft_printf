/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:39:31 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:39:34 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' ||
			s[len - 1] == '\t') && len > 0)
		len--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (len < i)
	{
		new = ft_strnew(len);
		return (new);
	}
	if (!(new = ft_strnew(len - i)))
		return (NULL);
	while (i < len)
		new[j++] = s[i++];
	return (new);
}
