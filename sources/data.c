/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:06:41 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/14 15:55:28 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_data		*new_data()
{
	t_data	*new;

	if (DEBUG)
		ft_putendl("new data");
	if (!(new = (t_data*)ft_memalloc(sizeof(t_data))))
		return (0);
	new->hash = 0;
	new->plus = 0;
	new->minus = 0;
	new->zero = 0;
	new->space = 0;
	new->hh = 0;
	new->h = 0;
	new->l = 0;
	new->ll = 0;
	new->j = 0;
	new->z = 0;
	new->mwidth = 0;
	new->precision = 1;
	new->fmt = 0;
	if (DEBUG)
		ft_putendl("end new data");
	return (new);
}

void	print_flags(t_data *new)
{
	if (DEBUG)
		ft_putendl("print flags");
	ft_putstr("hash : ");
    ft_putnbr(new->hash);
	ft_putchar('\n');
	ft_putstr("plus : ");
	ft_putnbr(new->plus);
	ft_putchar('\n');
	ft_putstr("minus : ");
	ft_putnbr(new->minus);
	ft_putchar('\n');
	ft_putstr("0 : ");
	ft_putnbr(new->zero);
	ft_putchar('\n');
	ft_putstr("space : ");
	ft_putnbr(new->space);
	ft_putchar('\n');
	ft_putstr("hh : ");
	ft_putnbr(new->hh);
	ft_putchar('\n');
	ft_putstr("h : ");
	ft_putnbr(new->h);
	ft_putchar('\n');
	ft_putstr("l : ");
	ft_putnbr(new->l);
	ft_putchar('\n');
	ft_putstr("ll : ");
	ft_putnbr(new->ll);
	ft_putchar('\n');
	ft_putstr("j : ");
	ft_putnbr(new->j);
	ft_putchar('\n');
	ft_putstr("z : ");
	ft_putnbr(new->z); 
	ft_putchar('\n');
}
