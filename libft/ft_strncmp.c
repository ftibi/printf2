/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:53:06 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:33:58 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s11, const char *s22, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (0);
	s1 = (unsigned char*)s11;
	s2 = (unsigned char*)s22;
	i = 0;
	while (*s1 && *s2 && i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return ((i == n) ? 0 : *s1 - *s2);
}
