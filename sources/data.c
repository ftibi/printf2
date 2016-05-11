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

t_data		*new_data(void)
{
	t_data	*new;

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
	new->precision = -1;
	new->fmt = 0;
	return (new);
}
