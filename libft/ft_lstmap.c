/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:28:43 by jeckhard          #+#    #+#             */
/*   Updated: 2019/09/15 21:28:44 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst && (new = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		new = f(lst);
		new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
