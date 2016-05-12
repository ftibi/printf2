/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:30:05 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 14:52:48 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*resp;
	int		i;

	if (!(s1 && s2))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	resp = (char*)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!resp)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		resp[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		resp[i] = s2[i - len1];
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
