/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_uncle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:28:50 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/17 15:28:52 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_tree_uncle(t_btree *node)
{
	t_btree *gparent;

	gparent = ft_tree_gparent(node);
	if (gparent == NULL)
		return (NULL);
	if (node->parent == gparent->left)
		return (gparent->right);
	else
		return (gparent->left);
}
