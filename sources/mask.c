/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:14:21 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 12:34:55 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	
	rev = ft_strdup(str);
	while (*rev)
		rev++;
	rev--;
	while (*str)
	{
		*rev = *str;
		rev--;
		str++;
	}
	return (rev);
}

char	*fill_mask(char *mask, int c)
{
	char	*tmp;
	char	*rev;
	char	*revmask;

	tmp = ft_itoa_base(c, 2);
	rev = ft_strrev(tmp);
	revmask = ft_strrev(mask);
	while (*revmask && *rev)
	{

	}
}

