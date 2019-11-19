/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_gparent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:28:50 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/17 15:28:52 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_tree_gparent(t_btree *node)
{
	if (node && node->parent)
		return (node->parent->parent);
	else
		return (NULL);
}
