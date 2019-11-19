/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_rotleft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:28:59 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/17 15:29:01 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_rotleft(t_btree *node)
{
	t_btree *pivot;

	pivot = node->right;
	pivot->parent = node->parent;
	if (node->parent)
	{
		if (node->parent->left == node)
			node->parent->left = pivot;
		else
			node->parent->right = pivot;
	}
	node->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = node;
	node->parent = pivot;
	pivot->left = node;
}
