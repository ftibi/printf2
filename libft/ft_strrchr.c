/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:30:36 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 15:25:48 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char *save;
	char *parse;

	save = NULL;
	parse = (char*)str;
	while (*parse)
	{
		if (*parse == (char)c)
			save = parse;
		parse++;
	}
	if (c == 0)
		return (parse);
	return (save);
}
