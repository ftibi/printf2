/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:34:56 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/10 18:00:13 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_printf_putstr(char *str);
int		ft_printf_putnbr(int nb);
int		ft_printf_puthexa(int nb);
int		ft_printf_putptr(unsigned long nb);

#endif
