/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 12:06:45 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/27 15:48:30 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_fct	*new_fct(void *fct, char conv)
{
	t_fct	*new_fct;

	if (!(new_fct = (t_fct*)ft_memalloc(sizeof(t_fct))))
		return (0);
	new_fct->fct = fct;
	new_fct->conv = conv;
	new_fct->next = NULL;
	return (new_fct);
}

static t_fct		*add_fct(t_fct *start, void *fct, char conv)
{
	t_fct	*tmp;

	if (!start)
		return (new_fct(fct, conv));
	tmp = start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_fct(fct, conv);
	return (start);
}

void						*get_fct(t_fct *start, char conv, t_data *data)
{
	if (!ft_strchr("idDxXoOuUsScCpP", conv))
		conv = 'Z';
	if (data->l && (conv == 'd' || conv == 'i'))
		conv = 'D';
	if (data->l && (conv == 's'))
		conv = 'S';
	if (data->l && conv == 'c')
		conv = 'C';
	if (data->l && conv == 'o')
		conv = 'O';
	if (data->l && conv == 'u')
		conv = 'U';
	if (data->l && (conv == 'x' || conv == 'X'))
		conv = 'H';
	if ((data->ll || data->j || data->z) && conv == 'u')
		conv = 'I';
	if ((data->ll || data->j || data->z) && (conv == 'd' || conv == 'i'))
		conv = 'F';
	if ((data->ll || data->j || data->z) && (conv == 'x' || conv == 'X'))
		conv = 'H';
	if ((data->ll || data->j || data->z) && conv == 'o')
		conv = 'P';
	if (data->hh && (conv == 'd' || conv == 'i'))
		conv = 'h';
	if (data->hh && conv == 'u')
		conv = 'a';
	if (data->hh && conv == 'o')
		conv = 'k';
	if (data->h && conv == 'o')
		conv = 'l';
	if (data->h && (conv == 'd' || conv == 'i'))
		conv = 'r';
	if (data->hh && (conv == 'x' || conv == 'X'))
		conv = 'v';
	while (start)
	{
		if (start->conv == conv)
			return (start->fct);
		else
			start = start->next;
	}
	return (0);
}

t_fct						*fct_init(void)
{
	t_fct	*list;

	if (DEBUG)
		ft_putendl("fct init");
	list = new_fct(ft_printf_putchar, 'c');
	list = add_fct(list, ft_printf_putstr, 's');
	list = add_fct(list, ft_printf_puthhnbr, 'h');
	list = add_fct(list, ft_printf_putnbr, 'i');
	list = add_fct(list, ft_printf_putnbr, 'd');
	list = add_fct(list, ft_printf_putlnbr, 'D');
	list = add_fct(list, ft_printf_putllnbr, 'F');
	list = add_fct(list, ft_printf_putuhhnbr, 'a');
	list = add_fct(list, ft_printf_puthnbr, 'r');
	list = add_fct(list, ft_printf_putunbr, 'u');
	list = add_fct(list, ft_printf_putlunbr, 'U');
	list = add_fct(list, ft_printf_putllunbr, 'I');
	list = add_fct(list, ft_printf_puthhhexa, 'v');
	list = add_fct(list, ft_printf_puthexa, 'x');
	list = add_fct(list, ft_printf_puthexa, 'X');
	list = add_fct(list, ft_printf_putlhexa, 'H');
	list = add_fct(list, ft_printf_putllhexa, 'J');
	list = add_fct(list, ft_printf_putptr, 'p');
	list = add_fct(list, ft_printf_puthhoct, 'k');
	list = add_fct(list, ft_printf_puthoct, 'l');
	list = add_fct(list, ft_printf_putoct, 'o');
	list = add_fct(list, ft_printf_putloct, 'O');
	list = add_fct(list, ft_printf_putlloct, 'P');
	list = add_fct(list, ft_printf_putlchar, 'C');
	list = add_fct(list, ft_printf_putlstr, 'S');
	return (list);
}
