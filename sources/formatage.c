/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:01:37 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/28 16:45:21 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			lst_finish(t_lst *lst, t_data *data)
{
	int	count;

	lst = format_lst(lst, data);
	print_lst(lst);
	count = lst_len(lst);
	free_lst(lst);
	return (count);
}

t_lst		*format_lst(t_lst *lst, t_data *data)
{
	lst = hashfmt(lst, data);
	lst = plusfmt(lst, data);
	lst = precisionfmt(lst, data);
	lst = mwidthfmt(lst, data);
	lst = spacefmt(lst, data);
	return (lst);
}

t_lst		*hashfmt(t_lst *lst, t_data *data)
{
	if (data->hash)
	{
		if ((*(data->fmt) == 'o' || *(data->fmt) == 'O') && lst->c != '0')
			lst = pushfront_lst(lst, '0');
		if (*(data->fmt) == 'x' && lst->c != '0' && data->precision)
		{
			lst = pushfront_lst(lst, 'x');
			lst = pushfront_lst(lst, '0');
		}
		if (*(data->fmt) == 'X' && lst->c != '0' && data->precision)
		{
			lst = pushfront_lst(lst, 'X');
			lst = pushfront_lst(lst, '0');
		}
	}
	return (lst);
}

t_lst		*plusfmt(t_lst *lst, t_data *data)
{
	if (data->plus && ft_strchr("idD", *(data->fmt)) && (lst->c != '-'))
		lst = pushfront_lst(lst, '+');
	return (lst);
}

t_lst		*spacefmt(t_lst *lst, t_data *data)
{
	t_lst	*start;

	if (!lst)
		return (0);
	if (!data->space || data->plus)
		return (lst);
	start = lst;
	if (ft_strchr("idD", *(data->fmt)))
	{
		if (ft_isdigit(lst->c) || lst->c == ' ')
		{
			lst = pushfront_lst(lst, ' ');
			return (lst);
		}
	}
	return (start);
}
