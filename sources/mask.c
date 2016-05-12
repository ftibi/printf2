/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:14:21 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 14:49:12 by tfolly           ###   ########.fr       */
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
		str++;
		if (*str)
			rev--;
	}
	return (rev);
}

void	fill_maskb(char **mask2, char **rev2, char *start_mask)
{
	char	*mask;
	char	*rev;

	mask = *mask2;
	rev = *rev2;
	while (mask != start_mask && *rev)
	{
		if (*mask == 'x')
		{
			*mask = *rev;
			rev++;
		}
		mask--;
	}
}

char	*fill_mask(char *mask, int c)
{
	char	*tmp;
	char	*rev;
	char	*start_rev;
	char	*start_mask;

	tmp = ft_itoa_base(c, 2);
	rev = ft_strrev(tmp);
	start_rev = rev;
	start_mask = mask;
	while (*mask)
		mask++;
	mask--;
	fill_maskb(&mask, &rev, start_mask);
	if (*rev)
		*mask = *rev;
	while (*mask)
	{
		if (*mask == 'x')
			*mask = '0';
		mask++;
	}
	free(start_rev);
	free(tmp);
	return (start_mask);
}

t_lst	*print_mask(char *mask, int oct, t_lst *lst)
{
	int			i;
	int			j;
	char		c[4];

	i = 0;
	while (i < oct)
	{
		j = 7;
		c[i] = 0;
		while (j >= 0)
		{
			if (*mask == '1')
				c[i] += ft_pow(2, j);
			j--;
			mask++;
		}
		lst = pushback_lst(lst, c[i]);
		i++;
	}
	return (lst);
}
