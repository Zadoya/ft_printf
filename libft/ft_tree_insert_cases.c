/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_insert_cases.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:28:40 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/17 15:28:42 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	case4(t_btree *node)
{
	t_btree	*gparent;

	gparent = ft_tree_gparent(node);
	node->parent->color = 1;
	gparent->color = 0;
	if ((node == node->parent->left) && (node->parent == gparent->left))
		ft_tree_rotright(gparent);
	else
		ft_tree_rotleft(gparent);
}

static void	case3(t_btree *node)
{
	t_btree *gparent;

	gparent = ft_tree_gparent(node);
	if ((node == node->parent->right) && (node->parent == gparent->left))
	{
		ft_tree_rotleft(node->parent);
		node = node->left;
	}
	else if ((node == node->parent->left) && (node->parent == gparent->right))
	{
		ft_tree_rotright(node->parent);
		node = node->right;
	}
	case4(node);
}

static void	case2(t_btree *node)
{
	t_btree *u;
	t_btree *g;

	u = ft_tree_uncle(node);
	if (u && u->color == 0)
	{
		node->parent->color = 1;
		u->color = 1;
		g = ft_tree_gparent(node);
		g->color = 0;
		ft_tree_insert_cases(g);
	}
	else
		case3(node);
}

static void	case1(t_btree *node)
{
	if (node->parent == NULL)
		node->color = 1;
	else if (node->parent->color == 1)
		return ;
	else
		case2(node);
}

void		ft_tree_insert_cases(t_btree *node)
{
	case1(node);
}
