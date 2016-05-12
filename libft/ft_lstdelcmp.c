/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:12:59 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 16:18:20 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelcmp(t_list **begin, void (*del)(void *, size_t),
		int (cmp)(void *))
{
	t_list *tmp;
	t_list *prev;

	tmp = *begin;
	prev = tmp;
	while (tmp)
	{
		if ((tmp == *begin) && !cmp(tmp->content))
		{
			*begin = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = *begin;
		}
		else if (!cmp(tmp->content))
		{
			prev->next = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = prev->next;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
