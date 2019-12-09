/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_and_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:53:03 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/25 16:53:06 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_concat_and_free(char *head, char *tail)
{
	char	*tmp;

	tmp = tail;
	tail = ft_strjoin(head, tail);
	free(tmp);
	return (tail);
}
