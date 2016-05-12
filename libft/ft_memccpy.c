/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:59:24 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 16:03:53 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*src2;
	unsigned char		*dst2;
	size_t				i;
	unsigned char		comp;

	comp = (unsigned char)c;
	i = 0;
	src2 = (unsigned char*)src;
	dst2 = (unsigned char*)dst;
	while (i < n)
	{
		if (*src2 == comp)
		{
			*dst2 = (unsigned char)*src2;
			dst2++;
			return (dst2);
		}
		*dst2 = (unsigned char)*src2;
		i++;
		src2++;
		dst2++;
	}
	return (NULL);
}
