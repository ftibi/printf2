/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:14:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/27 16:16:18 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_putstr(t_data *data, va_list ap)
{
	int		count;
	char	*str;
	t_lst *lst;

	str = va_arg(ap, char*);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	lst = 0;
	while (*str)
	{
		lst = pushback_lst(lst, *str);
		str++;
	}
	lst = format_lst(lst, data);
	count = lst_len(lst);
	print_lst(lst);
	free_lst(lst);
	return (count);
}

int		ft_printf_putlunbr(t_data *data, va_list ap)
{
	unsigned  long long	pow;
	unsigned  long	res;
	unsigned  long	nb;
	t_lst						*lst;

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
	unsigned int	res;
	unsigned int			nb;
	t_lst					*lst;

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
	unsigned long	res;
	long long				nb;
	t_lst						*lst;

	lst = 0;
	nb = va_arg(ap, long);
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	if (nb < 0)
	{
		res = -nb;
		lst = pushback_lst(lst, '-');
	}
	else
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


int		ft_printf_putnbr(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned int	res;
	int				nb;
	t_lst			*lst;

	lst = 0;
	nb = va_arg(ap, int);
	if (nb == 0)
	{
			lst = pushback_lst(lst, '0');
			return (lst_finish(lst, data));
	}
	if (nb < 0)
	{
		res = -nb;
		lst = pushback_lst(lst, '-');
	}
	else
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

int		ft_printf_putchar(t_data *data, va_list ap)
{
	t_lst	*lst;
	char	c;

	lst = 0;
	c = va_arg(ap, int);
	lst = pushback_lst(lst, c);
	return (lst_finish(lst, data));
}
