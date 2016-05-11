/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:48:51 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 15:48:52 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_puthnbr(t_data *data, va_list ap)
{
	short			pow;
	unsigned short	res;
	short			nb;
	t_lst			*lst;

	lst = 0;
	nb = va_arg(ap, int);
	if (nb == 0)
		return (lst_finish(lst = pushback_lst(lst, '0'), data));
	if (nb < 0)
		lst = pushback_lst(lst, '-');
	res = (nb < 0) ? -nb : nb;
	pow = 1;
	while (pow <= res / 10)
		pow *= 10;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 10;
	}
	return (lst_finish(lst, data));
}
