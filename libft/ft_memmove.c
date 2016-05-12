/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:58:33 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/22 15:56:55 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;

	if (dst > src && dst < src + len)
	{
		dst2 = (char*)dst;
		src2 = (char*)src;
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
