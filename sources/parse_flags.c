/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:21:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 16:26:51 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_data	*parse_flags(char **fmt)
{
	t_data	*data;
	char	*format;
	int		nb;

	if (DEBUG)
		ft_putendl("parse flags");
	format = (char*)*fmt;
	format++;
//	ft_putchar(*format);
	data = new_data();
	while (format && *format && ft_strchr("#0-+ ", *format))
	{
		if (DEBUG)
			ft_putendl("parse flags 1.5");
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
		format++;
	}
	if (DEBUG)
		ft_putendl("parse flags 2");
	if (ft_isdigit(*format))
	{
		nb = *format - '0';
		format++;
		while (ft_isdigit(*format))
		{
			nb = 10 * nb + *format - '0';
			format++;
		}
		data->mwidth = nb;
	}
	if (DEBUG)
		ft_putendl("parse flags3");
	if (*format == '.')
	{
		format++;
		nb = 0;
		while (ft_isdigit(*format))
		{
			nb = 10 * nb + *format;
			format++;
		}
		data->precision = nb;
	}
	if (DEBUG)
		ft_putendl("parse flags4");
	while (format && *format && ft_strchr("hljz", *format))
	{
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
	if (DEBUG)
		ft_putendl("end parse flags");
	data->fmt = format;
//	ft_putendl(data->fmt);
	//ici modif data pour pouvoir passer lc en C par exemple
	data = data_mod(data);
	//fmt = &format;
	return (data);
}

t_data	*data_mod(t_data *data)
{
	if (*(data->fmt) == 'c' && data->l)
	{
		*(data->fmt) = 'C';
		data->l = 0;
	}
	return (data);
}
