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
	lst = mwidthfmt(lst, data);
	lst = plusfmt(lst, data);
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

    if (data->zero && !data->minus )//&&
        c = '0';
    else
        c = ' ';
//		printf("mwidth %d\n", data->mwidth);
//		printf("precision %d\n", data->precision);
		while (lst_len(lst) < data->mwidth)
    {
			if (data->minus)
				lst = pushback_lst(lst, c);
	    else
			{
				if (lst->c == '-' && c == '0')
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

t_lst		*plusfmt(t_lst *lst, t_data *data)
{
	data++;
	return (lst);
}
