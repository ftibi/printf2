/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:14:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/14 15:29:14 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_putptr(unsigned long nb, t_data *data)
{
	unsigned long	pow;
	unsigned long	res;
	int				count;

	data->mwidth = 1; //a retirer, c juste pour utiliser data
	count = 2;
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

int		ft_printf_puthexa(int nb, t_data *data)
{
	unsigned int	pow;
	unsigned int	res;
	int				count;

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

int		ft_printf_putstr(char *str, t_data *data)
{
	int		count;

	data->mwidth = 1; //a retirer, c juste pour utiliser data
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

int		ft_printf_putnbr(int nb, t_data *data)
{
	unsigned long long	pow;
	unsigned int	res;
	int				count;

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
