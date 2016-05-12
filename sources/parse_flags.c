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

	format = (char*)*fmt;
	data = new_data();
	format = parse_opt_flags(format, data);
	format = parse_mwidth_flag(format, data);
	format = parse_prec_flag(format, data);
	while (format && *format && ft_strchr("hljz", *format))
	{
		format = parse_jzh_flags(format, data);
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
	data->fmt = format;
	return (data);
}

char	*parse_opt_flags(char *format, t_data *data)
{
	while (format && *format && ft_strchr("#0-+ ", *format))
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
		format++;
	}
	return (format);
}

char	*parse_mwidth_flag(char *format, t_data *data)
{
	int	nb;

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
	return (format);
}

char	*parse_prec_flag(char *format, t_data *data)
{
	int	nb;
	int	i;

	if (*format == '.')
	{
		format++;
		nb = 0;
		i = 0;
		while (ft_isdigit(*format))
		{
			i++;
			nb = 10 * nb + *format - '0';
			format++;
		}
		data->precision = nb;
	}
	return (format);
}

char	*parse_jzh_flags(char *format, t_data *data)
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
	return (format);
}
