/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:28:29 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/17 15:28:31 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_insert(t_btree **root, t_btree *parent, t_btree *new_node,
					int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = new_node;
		(*root)->parent = parent;
		ft_tree_insert_cases(new_node);
	}
	else if (cmpf((*root)->content, new_node->content) > 0 && (root))
		ft_tree_insert(&((*root)->left), *root, new_node, cmpf);
	else
		ft_tree_insert(&((*root)->right), *root, new_node, cmpf);
}
