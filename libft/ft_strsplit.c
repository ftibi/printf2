/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:56:57 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 17:36:48 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_words(char const *s, char c)
{
	int i;
	int nb;
	int mot;

	i = 0;
	nb = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (mot == 0 && s[i] != c)
		{
			mot = 1;
			nb++;
		}
		if (s[i] == c)
		{
			mot = 0;
		}
		i++;
	}
	return (nb);
}

static char		*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char*)s);
}

static int		len_word(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**resp;
	int		nb;
	int		i;

	if (!s)
		return (NULL);
	s = next_word(s, c);
	nb = nbr_words(s, c);
	if (!(resp = malloc(sizeof(char*) * nb + 1)))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		if (!(resp[i] = (char *)malloc(sizeof(char) * len_word(s, c) + 1)))
			return (0);
		resp[i] = ft_memcpy(resp[i], s, len_word(s, c));
		resp[i][len_word(s, c)] = '\0';
		s = s + len_word(s, c);
		s = next_word(s, c);
		i++;
	}
	resp[i] = NULL;
	return (resp);
}
