/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:30:31 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:02:01 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*resp;
	char	*save;

	resp = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!resp)
		return (NULL);
	save = resp;
	while (*s1)
	{
		*resp = *s1;
		resp++;
		s1++;
	}
	*resp = *s1;
	return (save);
}
