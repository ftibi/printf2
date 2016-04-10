/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:14:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/10 16:34:03 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_putstr(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

int		ft_printf_putnbr(int nb)
{
	unsigned int	pow;
	unsigned int	res;
	int				count;

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
