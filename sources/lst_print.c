/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:42:47 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/28 16:12:55 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_error(int nb)
{
	nb++;
	exit(0);
}

t_lst		*lst_null(t_lst *lst)
{
	lst = pushback_lst(lst, '(');
	lst = pushback_lst(lst, 'n');
	lst = pushback_lst(lst, 'u');
	lst = pushback_lst(lst, 'l');
	lst = pushback_lst(lst, 'l');
	lst = pushback_lst(lst, ')');
	return (lst);
}

t_lst		*new_lst(char c)
{
	t_lst	*new;

	if (!(new = (t_lst*)ft_memalloc(sizeof(t_lst))))
		ft_error(-1);
	new->next = 0;
	new->c = c;
	return (new);
}

int			lst_sum_digit(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (ft_isdigit(lst->c))
			count += lst->c - '0';
		lst = lst->next;
	}
	return (count);
}
