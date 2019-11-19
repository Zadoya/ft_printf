/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:29:09 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/17 15:29:10 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_tree_new(const void *content, size_t content_size)
{
	t_btree *new;

	if (content == NULL || content_size == 0)
	{
		content = NULL;
		content_size = 0;
	}
	if ((new = (t_btree *)ft_memalloc(sizeof(t_btree))))
	{
		new->content = (void *)content;
		new->content_size = content_size;
		new->left = NULL;
		new->right = NULL;
		new->parent = NULL;
		new->color = 0;
	}
	return (new);
}
