/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:14:20 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/04 17:00:23 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*resp;
	size_t			i;

	if (len == 0)
	{
		resp = (char*)malloc(sizeof(char));
		if (!resp)
			return (NULL);
		*resp = '\0';
		return (resp);
	}
	if (s == NULL || s + start == NULL)
		return (NULL);
	resp = (char*)malloc(sizeof(char) * len + 1);
	if (!resp)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		resp[i] = s[i + start];
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
