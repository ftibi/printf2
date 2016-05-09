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
    if ((*(data->fmt) == 'o' || *(data->fmt) == 'O') && lst->c != '0')//&& data->precision != 0)//le premier char doit etre 0
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
			if (data->precision > 0 && lst_digit(lst) >= data->precision && ft_strchr("idDxXoOuU", *(data->fmt)))
				c = ' ';
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
	t_lst *start;
	int		count;

	if (data->precision == 0 && ft_strchr(ft_strdup("idDoOuUxX"), *(data->fmt)) && !data->hash) //&& !data->l && !data->ll && !data->h && !data->hh && !data->j && !data->z)
	{
		if (lst_sum_digit(lst) == 0)
			lst = del_all_digits(lst)	;// ne pas delete tous les 0 si # ATTENTION A CORRIGER
}

	if (data->precision == 0 && ((ft_strchr(ft_strdup("xX"), *(data->fmt)) && data->hash) || (ft_strchr(ft_strdup("pP"), *(data->fmt))))) //&& !data->l && !data->ll && !data->h && !data->hh && !data->j && !data->z)
		if (lst_sum_alnum(lst) == 0) //fonction a implementer pourles pointeurs
		{
			lst = del_all_digits(lst)	;
			lst = pushfront_lst(lst, '0');
		}
			//ilf aut retirer la condition sur !datahash et laisser juste 1 zero si datahash
		// if (*(data->fmt) == 'O')
		// 	lst = pushfront_lst(lst, '0');
	if (data->precision > 0)
	{
		if (ft_strchr(ft_strdup("idDxXoOuU"), *(data->fmt)))
		{
			while (lst_len(lst) < data->precision + (lst->c == '-'))
			{
				if (lst->c == '-')
				{
					lst->next = pushfront_lst(lst->next, '0');
				}
				else
					lst = pushfront_lst(lst, '0');
			}
		}
		else if (ft_strchr(ft_strdup("s"), *(data->fmt)))
		{
			if (lst_len(lst) > data->precision)
			{
				//ici il faut cut la string et changer mwidth
				data->mwidth = data->precision;
				start = lst;
				count = data->precision;
				while (count > 1)
				{
					lst = lst->next;
					count--;
				}
				lst->next = 0;
				free_lst(lst->next);
				return (start);
			}
		}
		if (*(data->fmt) == 'p' || (data->hash && ((*(data->fmt) == 'x' || *(data->fmt) == 'X'))))
		{
			// ft_putendl("ici");
			while (data->precision > lst_len(lst) - 2)
			{
			//  ft_putendl("ici");
				lst->next->next = pushfront_lst(lst->next->next, '0');
			}
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
