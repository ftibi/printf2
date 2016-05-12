/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_basemaj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:59:34 by tfolly            #+#    #+#             */
/*   Updated: 2016/02/01 16:24:55 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_init_itoa(unsigned long long nb, unsigned int base,
		unsigned long long *pow)
{
	char	*ret;

	*pow = 1;
	while (nb >= base)
	{
		nb /= base;
		(*pow)++;
	}
	if (!(ret = ft_strnew(*pow)))
		return (NULL);
	*pow = ft_ulpow(base, *pow - 1);
	return (ret);
}

static char		ft_char_itoa(unsigned long long pow, unsigned long long nb)
{
	char	ret;

	ret = nb / pow;
	if (ret >= 10)
		ret += 'A' - 10;
	else
		ret += '0';
	return (ret);
}

char			*ft_uitoa_basemaj(unsigned long long nb, unsigned int base)
{
	char				*ret;
	char				*save;
	unsigned long long	pow;

	if (!(ret = ft_init_itoa(nb, base, &pow)))
		return (NULL);
	save = ret;
	while (pow > 0)
	{
		*ret = ft_char_itoa(pow, nb);
		nb = nb % pow;
		pow = pow / base;
		ret++;
	}
	return (save);
}
