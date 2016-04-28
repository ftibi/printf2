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

void	ft_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

t_lst	*new_lst(char c)
{
	t_lst	*new;

	if (!(new = (t_lst*)ft_memalloc(sizeof(t_lst))))
		ft_error("malloc error");
	new->next = 0;
	new->c = c;
	return (new);
}

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

void				print_lst(t_lst *lst)
{
	while (lst)
	{
		ft_putchar(lst->c);
		lst = lst->next;
	}
}

void				free_lst(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
