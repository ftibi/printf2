/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:28:01 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 13:49:50 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*s11;
	unsigned char		*s22;

	if (n == 0)
		return (0);
	i = 0;
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (i < n)
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		s11++;
		s22++;
		i++;
	}
	return (0);
}
