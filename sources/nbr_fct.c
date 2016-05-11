/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:14:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/27 16:16:18 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_putlunbr(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned long		res;
	unsigned long		nb;
	t_lst				*lst;

	lst = 0;
	nb = va_arg(ap, unsigned long);
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	res = nb;
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

int		ft_printf_putunbr(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned int		res;
	unsigned int		nb;
	t_lst				*lst;

	nb = va_arg(ap, unsigned int);
	lst = 0;
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	res = nb;
	pow = 1;
	while (pow <= res)
		pow *= 10;
	pow /= 10;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 10;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_putlnbr(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned long		res;
	long long			nb;
	t_lst				*lst;

	lst = 0;
	nb = va_arg(ap, long);
	if (nb == 0)
		return (lst_finish(pushback_lst(lst, '0'), data));
	if (nb < 0)
		lst = pushback_lst(lst, '-');
	res = (nb < 0) ? -nb : nb;
	pow = 1;
	while (pow <= res)
		pow *= 10;
	pow /= 10;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 10;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_putnbr(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned int		res;
	int					nb;
	t_lst				*lst;

	lst = 0;
	nb = va_arg(ap, int);
	if (nb == 0)
		return (lst_finish(pushback_lst(lst, '0'), data));
	if (nb < 0)
		lst = pushback_lst(lst, '-');
	res = (nb < 0) ? -nb : nb;
	pow = 1;
	while (pow <= res)
		pow *= 10;
	pow /= 10;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 10;
	}
	return (lst_finish(lst, data));
}
