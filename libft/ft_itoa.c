/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:59:34 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/22 15:52:31 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_init_itoa(unsigned int nb, unsigned int base,
		unsigned int *pow, int signe)
{
	char	*ret;

	*pow = 1;
	while (nb >= base)
	{
		nb /= base;
		(*pow)++;
	}
	if (!(ret = ft_strnew(*pow + (signe == -1))))
		return (NULL);
	*pow = ft_pow(base, *pow - 1);
	return (ret);
}

static char		*ft_signe_itoa(int signe, char *ret)
{
	if (signe == -1)
	{
		*ret = '-';
		ret++;
	}
	return (ret);
}

static char		ft_char_itoa(unsigned int pow, int nb)
{
	char	ret;

	ret = nb / pow;
	if (ret >= 10)
		ret += 'a' - 10;
	else
		ret += '0';
	return (ret);
}

char			*ft_itoa(int nbr)
{
	char			*ret;
	char			*save;
	int				signe;
	unsigned int	pow;
	unsigned int	nb;

	signe = (nbr >= 0) ? 1 : -1;
	if (signe == -1)
		nb = -1 * nbr;
	else
		nb = nbr;
	if (!(ret = ft_init_itoa(nb, 10, &pow, signe)))
		return (NULL);
	save = ret;
	ret = ft_signe_itoa(signe, ret);
	while (pow > 0)
	{
		*ret = ft_char_itoa(pow, nb);
		nb = nb % pow;
		pow = pow / 10;
		ret++;
	}
	return (save);
}
