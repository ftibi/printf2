/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:48:25 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 15:48:27 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_lst		*prec_null_fmt(t_lst *lst, t_data *data)
{
	if (data->precision == 0 && ft_strchr("idDoOuUxX",
			*(data->fmt)) && !data->hash && (lst_sum_digit(lst) == 0))
		lst = del_all_digits(lst)	;
	if (data->precision == 0 && ((ft_strchr("xX", *(data->fmt))
			&& data->hash) || (ft_strchr("pP", *(data->fmt)))))
	{
		if (lst_sum_alnum(lst) == 0)
		{
			lst = del_all_digits(lst)	;
			if (*(data->fmt) == 'p' || *(data->fmt) == 'P')
				lst = pushfront_lst(lst, '0');
		}
	}
	return (lst);
}

static t_lst		*pos_pres_s(t_lst *lst, t_data *data)
{
	int		count;
	t_lst	*start;
	t_lst	*tmp;

	if (!data->precision)
	{
		free_lst(lst);
		return (0);
	}
	if (lst_len(lst) > data->precision)
	{
		start = lst;
		count = data->precision;
		while (count > 1)
		{
			lst = lst->next;
			count--;
		}
		tmp = lst->next;
		lst->next = 0;
		free_lst(tmp);
		return (start);
	}
	return (lst);
}

static t_lst		*pos_pres_fmt(t_lst *lst, t_data *data)
{
	if (*(data->fmt) == 'p' || (data->hash && ((*(data->fmt) == 'x' ||
			*(data->fmt) == 'X'))))
	{
		while (data->precision > lst_len(lst) - 2)
			lst->next->next = pushfront_lst(lst->next->next, '0');
	}
	if (ft_strchr("idDxXoOuU", *(data->fmt)))
	{
		while (lst_len(lst) < data->precision + (lst->c == '-') +
				(lst->c == '+'))
		{
			if (lst->c == '-' || (lst->c == '+'))
				lst->next = pushfront_lst(lst->next, '0');
			else
				lst = pushfront_lst(lst, '0');
		}
	}
	return (lst);
}

t_lst				*precisionfmt(t_lst *lst, t_data *data)
{
	lst = prec_null_fmt(lst, data);
	if (data->precision >= 0 && ft_strchr("sS", *(data->fmt)))
		lst = pos_pres_s(lst, data);
	else if (data->precision > 0)
		lst = pos_pres_fmt(lst, data);
	return (lst);
}
