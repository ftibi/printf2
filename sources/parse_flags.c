/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:21:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/11 14:58:36 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_data	*parse_flags(const char **fmt)
{
	t_data	*data;
	char	*format;
    char    *ptr;
    char    flags[] = "#0-+ hljz";


    //il vaut mieux renvoyer format et modif data via le pointeur
	if (DEBUG)
		ft_putendl("parse flags");
	format = (char*)*fmt;
	data = new_data();
	while (format && *format && (*(ptr = ft_strchr(flags, (int)*format))))
	{
		if (*format == '#')
			data->hash = 1;
		if (*format == '0')
			data->zero = 1;
		if (*format == '-')
			data->minus = 1;
		if (*format == '+')
			data->plus = 1;
		if (*format == ' ')
			data->space = 1;
		if (*format == 'j')
			data->j = 1;
		if (*format == 'z')
			data->z = 1;
		if (*format == 'h')
		{
			if (*(format + 1) == 'h')
			{
				data->hh = 1;
				format++;
			}
			else
				data->h = 1;
		}
		if (*format == 'l')
		{
			if (*(format + 1) == 'l')
			{
				data->ll = 1;
				format++;
			}
			else
				data->l = 1;
		}
		format++;
    }
	return (data);
}
