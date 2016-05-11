/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:43:14 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 10:43:16 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_puthhnbr(t_data *data, va_list ap)
{
	unsigned char	pow;
	unsigned char	res;
	char			nb;
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

int		ft_printf_putuhhnbr(t_data *data, va_list ap)
{
	unsigned char	pow;
	unsigned char	res;
	t_lst			*lst;

	lst = 0;
	res = va_arg(ap, int);
	if (res == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
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

int		ft_printf_puthhoct(t_data *data, va_list ap)
{
	unsigned int	pow;
	unsigned char	res;
	t_lst			*lst;

	lst = 0;
	res = va_arg(ap, int);
	if (res == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	pow = 1;
	while (pow <= res)
		pow *= 8;
	pow /= 8;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 8;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_puthoct(t_data *data, va_list ap)
{
	unsigned short	pow;
	unsigned short	res;
	t_lst			*lst;

	lst = 0;
	res = va_arg(ap, int);
	if (res == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	pow = 1;
	while (pow <= res / 8)
		pow *= 8;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 8;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_puthhhexa(t_data *data, va_list ap)
{
	unsigned int	pow;
	unsigned char	res;
	t_lst			*lst;

	lst = 0;
	res = va_arg(ap, int);
	if (res == 0)
		return (lst_finish(pushback_lst(lst, '0'), data));
	pow = 1;
	while (pow <= res / 16)
		pow *= 16;
	while (pow)
	{
		if (res / pow < 10)
			lst = pushback_lst(lst, '0' + res / pow);
		else if (*(data->fmt) == 'x')
			lst = pushback_lst(lst, 'a' + res / pow - 10);
		else
			lst = pushback_lst(lst, 'A' + res / pow - 10);
		res = res - (res / pow) * pow;
		pow /= 16;
	}
	return (lst_finish(lst, data));
}
