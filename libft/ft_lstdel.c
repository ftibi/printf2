/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:08:32 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 15:28:29 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*parse;

	if (*alst)
	{
		parse = *alst;
		while (parse)
		{
			next = parse->next;
			ft_lstdelone(&parse, del);
			parse = next;
		}
		*alst = NULL;
	}
}
