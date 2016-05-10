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

//	ft_putendl("str rev");
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

char	*fill_mask(char *mask, int c)
{
	char	*tmp;
	char	*rev;
	char	*start_mask;

//	ft_putendl("fill mask");
	tmp = ft_itoa_base(c, 2);
	rev = ft_strrev(tmp);
	start_mask = mask;
	while (*mask)
		mask++;
	mask--;
	while (mask != start_mask && *rev)
	{
		if (*mask == 'x')
		{
			*mask = *rev;
			rev++;
		}
		mask--;
	}
	if (*rev)
		*mask = *rev;
	while (*mask)
	{
		if(*mask == 'x')
			*mask = '0';
		mask++;
	}
	return (start_mask);
}

int		print_mask(char *mask, int oct, t_data *data)
{
	int			i;
	int			j;
	char c[4];
	t_lst		*lst;

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
		i++;
	}
	i = 0;
	lst = 0;
	while (i < oct)
	{
		//write(1, &c[i], 1);
		lst = pushback_lst(lst, c[i]);
		i++;
	}
	i = lst_finish(lst, data);
	return (i);
}
