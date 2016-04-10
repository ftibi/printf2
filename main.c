/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:44:53 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/10 16:33:17 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(int ac, char **av)
{
	int	res;

	res = ft_printf("Salut comment %s va ?\n", "ca");
	ft_putnbr(res);
	ft_putchar('\n');

	ft_printf_putnbr(00);
	ft_putchar('\n');



	return (0);
}
