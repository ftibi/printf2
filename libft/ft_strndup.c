/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:44:17 by tfolly            #+#    #+#             */
/*   Updated: 2016/01/13 16:15:05 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*resp;
	char		*save;
	size_t		i;

	resp = (char*)ft_memalloc(n + 1);
	if (!resp)
		return (NULL);
	save = resp;
	i = 0;
	while (*s1 && i < n)
	{
		*resp = *s1;
		resp++;
		s1++;
		i++;
	}
	*resp = '\0';
	return (save);
}
