/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:34:56 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/11 14:58:39 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# define DEBUG 1

int		ft_printf(const char *format, ...);

typedef struct	s_data
{
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_data;

t_data	*parse_flags(const char **fmt);
t_data	*new_data(void);

void	print_flags(t_data *data);

int		ft_printf_putstr(char *str);
int		ft_printf_putnbr(int nb);
int		ft_printf_puthexa(int nb);
int		ft_printf_putptr(unsigned long nb);

#endif
