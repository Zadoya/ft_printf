/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_rotright.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:28:59 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/17 15:29:01 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_rotright(t_btree *node)
{
	t_btree	*pivot;

	pivot = node->left;
	pivot->parent = node->parent;
	if (node->parent)
	{
		if (node->parent->left == node)
			node->parent->left = pivot;
		else
			node->parent->right = pivot;
	}
	node->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = node;
	node->parent = pivot;
	pivot->right = node;
}
