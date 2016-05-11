/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:24:40 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 10:24:42 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst		*two_oct(int c, t_lst *lst)
{
	char *mask;

	mask = ft_strdup("110xxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	lst = print_mask(mask, 2, lst);
	free(mask);
	return (lst);
}

t_lst		*three_oct(int c, t_lst *lst)
{
	char *mask;

	mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	lst = print_mask(mask, 3, lst);
	free(mask);
	return (lst);
}

t_lst		*four_oct(int c, t_lst *lst)
{
	char *mask;

	mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	lst = print_mask(mask, 4, lst);
	free(mask);
	return (lst);
}

int			ft_printf_putlstr(t_data *data, va_list ap)
{
	int		count;
	int		*str;
	t_lst	*lst;

	lst = 0;
	str = va_arg(ap, int*);
	if (!str)
		lst = lst_null(lst);
	while (str && *str)
	{
		if (*str < 128)
			lst = pushback_lst(lst, *str);
		else if (*str < 2048)
			lst = two_oct(*str, lst);
		else if (*str < ft_pow(2, 15) * 2 - 1)
			lst = three_oct(*str, lst);
		else
			lst = four_oct(*str, lst);
		str++;
	}
	count = lst_finish(lst, data);
	return (count);
}

int			ft_printf_putlchar(t_data *data, va_list ap)
{
	int		c;
	t_lst	*lst;
	int		count;

	lst = 0;
	c = va_arg(ap, int);
	if (c < 128)
		lst = pushback_lst(lst, c);
	else if (c < 2048)
		lst = two_oct(c, lst);
	else if (c < ft_pow(2, 15) * 2 - 1)
		lst = three_oct(c, lst);
	else
		lst = four_oct(c, lst);
	count = lst_finish(lst, data);
	return (count);
}
