/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:22:21 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 13:32:58 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*save;
	t_list	*prev;

	if (!lst)
		return (NULL);
	save = NULL;
	prev = NULL;
	while (lst)
	{
		newlst = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (!newlst)
			return (NULL);
		if (prev)
			prev->next = newlst;
		if (save == NULL)
			save = newlst;
		prev = newlst;
		lst = lst->next;
	}
	return (save);
}
