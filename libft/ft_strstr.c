/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:39:59 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:17:31 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*parsingfct(char *res, char *s2parse, char *s1parse)
{
	char *s2;
	char *save;

	s2 = s2parse;
	while (res != NULL)
	{
		save = s1parse;
		res = ft_strchr(s1parse, (int)*s2parse);
		while (res != NULL && *s1parse == *s2parse && *s2parse != '\0')
		{
			s1parse++;
			s2parse++;
		}
		if (*s2parse == '\0')
		{
			return (res);
		}
		s2parse = (char*)s2;
		s1parse = save + 1;
	}
	return (res);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	char	*res;
	char	*s2parse;
	char	*s1parse;

	s1parse = (char*)s1;
	s2parse = (char*)s2;
	res = ft_strchr(s1parse, (int)*s2parse);
	if (!res)
		return (NULL);
	if (*s2 == '\0')
		return ((char*)s1);
	return (parsingfct(res, s2parse, s1parse));
}
