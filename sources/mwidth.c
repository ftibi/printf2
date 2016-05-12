/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mwidth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:21:47 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 16:21:48 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_lst		*mwidthfmtb(t_lst *lst, t_data *data, char c)
{
	if (lst && (lst->c == '-' || lst->c == '+') && c == '0')
		lst->next = pushfront_lst(lst->next, c);
	else if ((*(data->fmt) == 'p' || ((*(data->fmt) == 'x' ||
			*(data->fmt) == 'X') && data->hash)) && c == '0')
		lst->next->next = pushfront_lst(lst->next->next, '0');
	else
		lst = pushfront_lst(lst, c);
	return (lst);
}

t_lst				*mwidthfmt(t_lst *lst, t_data *data)
{
	char	c;
	int		space;

	space = 1;
	if (data->zero && !data->minus)
		c = '0';
	else
		c = ' ';
	while (lst_len(lst) < data->mwidth)
	{
		if (ft_strchr("idDxXoOuU", *(data->fmt)) && data->space && space)
		{
			data->mwidth--;
			space = 0;
		}
		if (data->precision > 0 && lst_digit(lst) >= data->precision &&
				ft_strchr("idDxXoOuU", *(data->fmt)))
			c = ' ';
		if (data->minus)
			lst = pushback_lst(lst, c);
		else
			lst = mwidthfmtb(lst, data, c);
	}
	return (lst);
}
