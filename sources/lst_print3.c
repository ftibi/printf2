/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:06:34 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 16:06:35 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					lst_sum_alnum(t_lst *lst)
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

static t_lst		*del_first_digit(t_lst *lst)
{
	t_lst		*tmp;

	while (lst && ft_isdigit(lst->c))
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (lst);
}

t_lst				*del_all_digits(t_lst *lst)
{
	t_lst		*start;
	t_lst		*prev;
	t_lst		*tmp;

	lst = del_first_digit(lst);
	start = lst;
	prev = lst;
	while (lst)
	{
		if (ft_isdigit(lst->c))
		{
			prev->next = lst->next;
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
	return (start);
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
		tmp = 0;
	}
}
