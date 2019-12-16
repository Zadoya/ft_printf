/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_and_freehead.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:41:41 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/09 16:41:44 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_concat_and_freehead(char *head, char *tail)
{
	char	*tmp;

	tmp = head;
	head = ft_strjoin(head, tail);
	free(tmp);
	return (head);
}
