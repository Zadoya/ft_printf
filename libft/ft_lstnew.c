/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:28:54 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:28:56 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = (void *)malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	if (content == NULL || content_size == 0)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
