/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:25:25 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 16:55:47 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lststrsplit(char const *str, char c)
{
	char	**tab;
	t_list	*newlst;
	t_list	*newelem;

	tab = ft_strsplit(str, c);
	newlst = ft_lstnew(*tab, ft_strlen(*tab) + 1);
	tab++;
	while (*tab)
	{
		newelem = ft_lstnew(*tab, ft_strlen(*tab) + 1);
		ft_lstaddend(&newlst, newelem);
		tab++;
	}
	ft_memdel((void**)tab);
	return (newlst);
}
