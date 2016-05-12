/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:28:44 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 14:59:59 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	char	*save;

	if (s && f)
	{
		newstr = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!newstr)
			return (NULL);
		save = newstr;
		while (*s)
		{
			*newstr = f(*s);
			newstr++;
			s++;
		}
		*newstr = '\0';
		return (save);
	}
	return (NULL);
}
