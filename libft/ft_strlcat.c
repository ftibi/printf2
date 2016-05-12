/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:17:05 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/04 16:59:01 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		res;
	const char	*save;

	if (ft_strlen(dst) >= n)
		return (ft_strlen(src) + n);
	save = src;
	i = 0;
	res = ft_strlen(dst);
	while (*dst)
		dst++;
	while (i < n - res - 1)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	res += ft_strlen(save);
	return (res);
}
