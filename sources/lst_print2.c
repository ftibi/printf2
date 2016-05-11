/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:06:26 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 16:06:27 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst				*pushfront_lst(t_lst *lst, char c)
{
	t_lst	*new;

	new = new_lst(c);
	new->next = lst;
	return (new);
}

t_lst				*pushback_lst(t_lst *lst, char c)
{
	t_lst	*tmp;

	if (!lst)
		return (new_lst(c));
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_lst(c);
	return (lst);
}

int					lst_len(t_lst *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int					lst_digit(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (ft_isdigit(lst->c))
			count++;
		lst = lst->next;
	}
	return (count);
}
