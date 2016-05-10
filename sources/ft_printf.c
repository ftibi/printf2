/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:37:25 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/15 15:53:19 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fmt_read(t_data *data, va_list ap, int *count, t_fct *fct_lst)
{
	ft_function	fct;
	char 		*format;
	t_lst		*lst;

	if (DEBUG)
		ft_putendl("fmt read");
	format = data->fmt;
//	format++;
	if (!(*format))
	{
		//	ft_putchar(' ');
		//	format++;
		return (format);
	}
//	if (*format == ' ')
//		format++;
	fct = (ft_function)get_fct(fct_lst, *format, data);
	if (!fct)
	{
	//	ft_putendl("no function");
//		ft_putchar(*format);
		lst = new_lst(*format);
		*count += lst_finish(lst, data);
		format++;
		return (format);
	}
	else
	{
//		ft_putendl("read fct");
		(*count) += fct(data, ap);
	}
	format++;
	return (format);
}

int		ft_printf(const char *format2, ...)
{
	va_list		ap;
	int			count;
	t_data		*data;
	t_fct		*fct_lst;
	char		*format;

	format = ft_strdup(format2);
	count = 0;
	va_start(ap, format2);
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
			format = fmt_read(data, ap, &count, fct_lst);
		}
		//print_flags(data);
	}
	va_end(ap);
	return (count);
}
