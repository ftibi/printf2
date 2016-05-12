/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:43:59 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:02:30 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	*save;

	i = 0;
	save = dst;
	while (i < n && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (save);
}
