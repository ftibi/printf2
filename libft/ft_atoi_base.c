/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:16:52 by tfolly            #+#    #+#             */
/*   Updated: 2016/02/03 13:32:19 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cette version ne gere pas les nombres negatifs
** Pour l'instant limitee a un usage avec des bases <= 10
** Ca suffit pour lutilisation sur des binaires
*/

unsigned long	ft_atoi_base(char *str, int base)
{
	int				pow;
	unsigned long	res;

	pow = ft_strlen(str) - 1;
	res = 0;
	while (pow >= 0)
	{
		res += ft_pow(base, pow) * (*str - '0');
		pow--;
		str++;
	}
	return (res);
}
