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

t_lst		*precisionfmt(t_lst *lst, t_data *data)
{
	t_lst	*start;
	t_lst	*tmp;
	int		count;

	start = lst;
	if (data->precision == 0 && ft_strchr(ft_strdup("idDoOuUxX"),
			*(data->fmt)) && !data->hash && (lst_sum_digit(lst) == 0))
		lst = del_all_digits(lst)	;
	if (data->precision == 0 && ((ft_strchr(ft_strdup("xX"), *(data->fmt))
			&& data->hash) || (ft_strchr(ft_strdup("pP"), *(data->fmt)))))
	{
		if (lst_sum_alnum(lst) == 0)
		{
			lst = del_all_digits(lst)	;
			if (*(data->fmt) == 'p' || *(data->fmt) == 'P')
				lst = pushfront_lst(lst, '0');
		}
	}
	if (data->precision > 0 && ft_strchr(ft_strdup("S"), *(data->fmt)))
	{
		lst = 0;
	}
	else if (data->precision >= 0 && ft_strchr(ft_strdup("sS"), *(data->fmt)))
	{
		if (!data->precision)
		{
			free(lst);
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
	}
	if (data->precision > 0)
	{
		if (*(data->fmt) == 'p' || (data->hash && ((*(data->fmt) == 'x' ||
				*(data->fmt) == 'X'))))
		{
			while (data->precision > lst_len(lst) - 2)
				lst->next->next = pushfront_lst(lst->next->next, '0');
		}
		if (ft_strchr(ft_strdup("idDxXoOuU"), *(data->fmt)))
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
	}
	return (lst);
}
