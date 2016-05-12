/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:13:40 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/07 15:24:22 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **begin, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *begin;
	*begin = tmp->next;
	ft_lstdelone(&tmp, del);
}
