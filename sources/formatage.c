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

t_lst		*format(t_lst *lst, t_data *data)
{
	lst = hashfmt(lst, data);
	lst = mwidthfmt(lst, data);
	lst = plusfmt(lst, data);
	return (lst);
}

t_lst		*hashfmt(t_lst *lst, t_data *data);
t_lst		*mwidthfmt(t_lst *lst, t_data *data);
t_lst		*plusfmt(t_lst *lst, t_data *data);


