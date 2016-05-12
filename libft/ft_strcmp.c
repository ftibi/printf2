/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:31:21 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 14:28:13 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *parse1;
	unsigned char *parse2;

	parse1 = (unsigned char*)s1;
	parse2 = (unsigned char*)s2;
	while (*parse2 && *parse1 && *parse1 == *parse2)
	{
		parse1++;
		parse2++;
	}
	return ((*parse1 == *parse2) ? 0 : *parse1 - *parse2);
}
