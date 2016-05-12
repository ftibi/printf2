/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:44:43 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/07 18:09:51 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfold(t_list *lst, int (*f)(void *, void *))
{
	int	*res;
	int	*tmp;

	res = (int*)malloc(sizeof(int));
	tmp = (int*)lst->content;
	*res = *tmp;
	lst = lst->next;
	while (lst)
	{
		*res = f(res, lst->content);
		lst = lst->next;
	}
	return (*res);
}
