/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:08:21 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:17:44 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	setdebfin(int *debut, int *fin, const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (*debut == -1 && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			*debut = i;
		if (*debut != -1 && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			*fin = i;
		i++;
	}
}

char		*ft_strtrim(char const *s)
{
	int		debut;
	int		fin;
	int		i;
	char	*resp;

	if (!s)
		return (NULL);
	debut = -1;
	fin = 0;
	setdebfin(&debut, &fin, s);
	resp = (char*)malloc(sizeof(char) * (fin - debut) + 2);
	if (!resp)
		return (NULL);
	i = 0;
	while (i < fin - debut + 1)
	{
		resp[i] = s[i + debut];
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
