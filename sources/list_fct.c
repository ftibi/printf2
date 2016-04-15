/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 12:06:45 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 11:49:07 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_fct	*new_fct(void *fct, char conv)
{
	t_fct	*new;

	if(!(new = (t_fct*)ft_memalloc(sizeof(t_fct))))
		return (0);
	new->fct = fct;
	new->conv = conv;
	new->next = NULL;
	return (new);
}

static t_fct		*add_fct(t_fct *start, void *fct, char conv)
{
	t_fct	*tmp;

	if (!start)
		return (new_fct(fct, conv));
	tmp = start;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_fct(fct, conv);
	return (start);
}

void	*get_fct(t_fct *start, char conv)
{
	if (DEBUG)
		ft_putendl("get fct");
	while (start)
	{
		if (start->conv == conv)
			return (start->fct);
		else
			start = start->next;
	}
	return (0);
}

t_fct		*fct_init()
{
	t_fct	*list;

	if (DEBUG)
		ft_putendl("fct init");
	list = new_fct(ft_printf_putchar, 'c');
	list = add_fct(list, ft_printf_putstr, 's');
	list = add_fct(list, ft_printf_putnbr, 'i');
	list = add_fct(list, ft_printf_putnbr, 'd');
	list = add_fct(list, ft_printf_putnbr, 'u');
	list = add_fct(list, ft_printf_puthexa, 'x');
	list = add_fct(list, ft_printf_putptr, 'p');
	list = add_fct(list, ft_printf_putoct, 'o');
	list = add_fct(list, ft_printf_putlchar, 'C');
	return (list);
}
