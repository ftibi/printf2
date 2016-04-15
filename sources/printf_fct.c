/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:14:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 11:05:25 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_putptr(t_data *data, va_list ap)
{
	unsigned long	pow;
	unsigned long	res;
	int				count;
	int				nb;

	data->mwidth = 1; //a retirer, c juste pour utiliser data
	count = 2;

	nb = va_arg(ap, int);
	if (nb == 0)
	{
		ft_putchar('0');
		return (3);
	}
	res = nb;
	pow = 1;
	while (res / pow >= 16)
		pow *= 16;
	while (pow)
	{
		if (res / pow < 10)
			ft_putchar('0' + res / pow);
		else
			ft_putchar('a' + res / pow - 10);
		res = res - (res / pow) * pow;
		pow /= 16;
		count++;
	}
	return (count);	
}

int		ft_printf_puthexa(t_data *data, va_list ap)
{
	unsigned int	pow;
	unsigned int	res;
	int				count;
	int				nb;

	nb = va_arg(ap, int);
	data->mwidth = 1; //a retirer, c juste pour utiliser data
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	res = nb;
	pow = 1;
	while (res / pow >= 16)
		pow *= 16;
	while (pow)
	{
		if (res / pow < 10)
			ft_putchar('0' + res / pow);
		else
			ft_putchar('a' + res / pow - 10);
		res = res - (res / pow) * pow;
		pow /= 16;
		count++;
	}
	return (count);	
}

int		ft_printf_putstr(t_data *data, va_list ap)
{
	int		count;
	char	*str;

	data->mwidth = 1; //a retirer, c juste pour utiliser data
	str = va_arg(ap, char*);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

int		ft_printf_putnbr(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned int	res;
	int				count;
	int				nb;

	nb = va_arg(ap, int);
	data->mwidth = 1; //a retirer, c juste pour utiliser data
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb < 0)
	{
		res = -nb;
		ft_putchar('-');
		count++;
	}
	else
		res = nb;
	pow = 1;
	while (pow <= res)
		pow *= 10;
	pow /= 10;
	while (pow)
	{
		ft_putchar('0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 10;
		count++;
	}
	return (count);	
}

int		ft_printf_putchar(t_data *data, va_list ap)
{
	int		count;
	char	c;

	data->mwidth = 1;
	count = 0;
	c = (char)va_arg(ap, int);
	ft_putchar(c);
	return (1);
}
