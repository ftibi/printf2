/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:55:23 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 13:37:21 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	newlst = (t_list*)malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	if (content)
	{
		newlst->content_size = content_size;
		newlst->content = ft_memalloc(content_size);
		if (!newlst->content)
			return (NULL);
		ft_memcpy(newlst->content, content, content_size);
	}
	else
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	newlst->next = NULL;
	return (newlst);
}
