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

t_lst		*format_lst(t_lst *lst, t_data *data) //relire la doc pour voir si jai oublie qqch
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
	//ft_putendl("hashfmt")
	if (data->hash)
	{
    if ((*(data->fmt) == 'o' || *(data->fmt) == 'O') && lst->c != '0')//le premier char doit etre 0
        lst = pushfront_lst(lst, '0');
    if (*(data->fmt) == 'x' && lst->c != '0')
    {
        lst = pushfront_lst(lst, 'x');
        lst = pushfront_lst(lst, '0');
    }
    if (*(data->fmt) == 'X' && lst->c != '0')
    {
        lst = pushfront_lst(lst, 'X');
        lst = pushfront_lst(lst, '0');
    }
	}
    return (lst);
}

t_lst		*mwidthfmt(t_lst *lst, t_data *data)
{
    char    c;
		t_lst		*tmp;

    if (data->zero && !data->minus)//&&
        c = '0';
    else
        c = ' ';
		if (data->space && ft_strchr("idD",*(data->fmt)))
			data->mwidth--;
		while (lst_len(lst) < data->mwidth)
    {
			if (data->minus)
				lst = pushback_lst(lst, c);
	    else
			{
				if ((lst->c == '-' || lst-> c == '+') && c == '0')
				{
						tmp = lst->next;
						lst->next = new_lst(c);
						lst->next->next = tmp;
				}
				else
					lst = pushfront_lst(lst, c);
			}
		}
		return (lst);
}

t_lst		*precisionfmt(t_lst *lst, t_data *data)
{
	if (data->precision > 0 && ft_strchr("idDxXoOuU", *(data->fmt)))
	{
		while (lst_len(lst) < data->precision)
		{
			lst = pushfront_lst(lst, '0');
		}
	}
	return (lst);
}

t_lst		*plusfmt(t_lst *lst, t_data *data)
{
	if (data->plus && ft_strchr("idD",*(data->fmt)))
	{
		if (lst->c != '-')// && lst->c != '0')
				lst = pushfront_lst(lst, '+');
	}
	return (lst);
}

t_lst		*spacefmt(t_lst *lst, t_data *data)
{
	t_lst	*start;

	if (!data->space || data->plus)
		return (lst);
	start = lst;
	if (ft_strchr("idD",*(data->fmt)))
	{
		if (ft_isdigit(lst->c))
		{
			lst = pushfront_lst(lst, ' ');
			return (lst);
		}
	}
	return (start);
}
