/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:43:51 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 15:43:53 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_fct	*fct_initb(t_fct *list)
{
	list = add_fct(list, ft_printf_putstr, 's');
	list = add_fct(list, ft_printf_puthhnbr, 'h');
	list = add_fct(list, ft_printf_putnbr, 'i');
	list = add_fct(list, ft_printf_putnbr, 'd');
	list = add_fct(list, ft_printf_putlnbr, 'D');
	list = add_fct(list, ft_printf_putllnbr, 'F');
	list = add_fct(list, ft_printf_putuhhnbr, 'a');
	list = add_fct(list, ft_printf_puthnbr, 'r');
	list = add_fct(list, ft_printf_putunbr, 'u');
	list = add_fct(list, ft_printf_putlunbr, 'U');
	list = add_fct(list, ft_printf_putllunbr, 'I');
	list = add_fct(list, ft_printf_puthhhexa, 'v');
	list = add_fct(list, ft_printf_puthexa, 'x');
	list = add_fct(list, ft_printf_puthexa, 'X');
	list = add_fct(list, ft_printf_putlhexa, 'H');
	list = add_fct(list, ft_printf_putllhexa, 'J');
	return (list);
}

t_fct			*fct_init(void)
{
	t_fct	*list;

	if (DEBUG)
		ft_putendl("fct init");
	list = new_fct(ft_printf_putchar, 'c');
	list = add_fct(list, ft_printf_putptr, 'p');
	list = add_fct(list, ft_printf_puthhoct, 'k');
	list = add_fct(list, ft_printf_puthoct, 'l');
	list = add_fct(list, ft_printf_putoct, 'o');
	list = add_fct(list, ft_printf_putloct, 'O');
	list = add_fct(list, ft_printf_putlloct, 'P');
	list = add_fct(list, ft_printf_putlchar, 'C');
	list = add_fct(list, ft_printf_putlstr, 'S');
	list = fct_initb(list);
	return (list);
}
