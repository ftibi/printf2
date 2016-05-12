/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:17:23 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:05:18 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char *s;

	s = (char*)src;
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
