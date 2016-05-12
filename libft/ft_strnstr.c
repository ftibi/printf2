/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:18:19 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:36:22 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char			*s1cpy;
	unsigned char	index;

	s1cpy = ft_strdup(s1);
	if (n < ft_strlen(s1) + 1)
	{
		s1cpy[n] = '\0';
	}
	if (ft_strstr(s1cpy, s2))
	{
		index = ft_strlen(s1cpy) - ft_strlen(ft_strstr(s1cpy, s2));
		return ((char*)(s1 + index));
	}
	return (NULL);
}
