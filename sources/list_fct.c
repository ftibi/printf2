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

t_fct		*new_fct(void *fct, char conv)
{
	t_fct	*new_fct;

	if (!(new_fct = (t_fct*)ft_memalloc(sizeof(t_fct))))
		return (0);
	new_fct->fct = fct;
	new_fct->conv = conv;
	new_fct->next = NULL;
	return (new_fct);
}

t_fct		*add_fct(t_fct *start, void *fct, char conv)
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

static char	get_fctb(char conv, t_data *data)
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
	return (conv);
}

void		*get_fct(t_fct *start, char conv, t_data *data)
{
	conv = get_fctb(conv, data);
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

void		free_lstfct(t_fct *lst)
{
	t_fct	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = 0;
	}
}
