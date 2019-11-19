/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:38:03 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:38:04 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	rev;
	char	*first_rez;
	char	*first_n;

	first_n = (char *)needle;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		needle = first_n;
		if (*haystack == *needle)
		{
			first_rez = (char *)haystack;
			rev = len;
			while (*(++needle) && len && (*(++haystack) == *needle))
				len--;
			if ((*haystack == *needle && !(*needle)) || !(*needle))
				return (first_rez);
			len = rev;
			haystack = first_rez;
		}
		haystack++;
	}
	return (NULL);
}
