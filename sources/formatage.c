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

t_lst		*format(t_lst *lst, t_data *data) //relire la doc pour voir si jai oublie qqch
{
	lst = hashfmt(lst, data);
	lst = mwidthfmt(lst, data);
	lst = plusfmt(lst, data);
	return (lst);
}

t_lst		*hashfmt(t_lst *lst, t_data *data)
{
    if (*(data->fmt) == 'o')//le premier char doit etre 0
        ;
    if (*(data->fmt) == 'x')
    {
        lst = pushback_lst(lst, '0');
        lst = pushback_lst(lst, 'x');
    }
    if (*(data->fmt) == 'X')
    {
        lst = pushback_lst(lst, '0');
        lst = pushback_lst(lst, 'X');
    }
    return (lst);
}

t_lst		*mwidthfmt(t_lst *lst, t_data *data)
{
    char    c;

    if (data->zero && !data->minus)
        c = '0';
    else
        c = ' ';
    while (lst_len(lst) < data->mwidth)
    {
        lst = pushfront_lst(lst, c);
    }
    return (lst);
}

t_lst		*plusfmt(t_lst *lst, t_data *data);
