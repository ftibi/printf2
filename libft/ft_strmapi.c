/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:55:22 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 15:01:21 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	char			*save;

	if (s && f)
	{
		i = 0;
		res = (char*)malloc(ft_strlen(s) * sizeof(char) + 1);
		if (!res)
			return (NULL);
		save = res;
		while (*s)
		{
			*res = f(i, *s);
			res++;
			s++;
			i++;
		}
		*res = '\0';
		return (save);
	}
	return (NULL);
}
