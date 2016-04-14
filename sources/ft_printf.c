/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:37:25 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/14 16:02:18 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*fmt_read(t_data *data, va_list ap, int *count, t_fct *fct_lst)
{
	ft_function	fct;
	char 		*format;

	if (DEBUG)
		ft_putendl("fmt read");
	format = data->fmt;
	if (!(*format))
	{
		//	ft_putchar(' ');
		//	format++;
		return (format);	
	}
	if (*format == ' ')
		format++;
	fct = (ft_function)get_fct(fct_lst, *format);
	if (!fct)
	{
		ft_putchar(*format);
		format++;
		(*count)++;
		return (format);
	}
	else
	{
		ft_putendl("read fct");
		(*count) += fct(data, ap);
	}
	format++;
	return (format);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	t_data		*data;
	t_fct		*fct_lst;

	count = 0;
	va_start(ap, format);
	fct_lst = fct_init();
	while (*format)
	{
		while (*format != '%' && *format)
		{
			ft_putchar(*format);
			format++;
			count++;
		}
		if (*format == '%')
		{
			data = parse_flags(&format);
			ft_putchar(*format);
			ft_putchar('\n');
			data->fmt = (char*)format; //je peux faire ca dans parse flags
			format = fmt_read(data, ap, &count, fct_lst);
		}
		//print_flags(data);
	}
	va_end(ap);
	return (count);
}
