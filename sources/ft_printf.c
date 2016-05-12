/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:37:25 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/11 10:17:26 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fmt_read(t_data *data, va_list ap, int *count, t_fct *fct_lst)
{
	t_ft_function			fct;
	char					*format;
	t_lst					*lst;

	format = data->fmt;
	if (!(*format))
		return (format);
	fct = (t_ft_function)get_fct(fct_lst, *format, data);
	if (!fct)
	{
		lst = new_lst(*format);
		*count += lst_finish(lst, data);
		format++;
		return (format);
	}
	else
		(*count) += fct(data, ap);
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
	data = 0;
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
			format++;
			data = parse_flags((char**)&format);
			format = fmt_read(data, ap, &count, fct_lst);
		}
	}
	va_end(ap);
	free_lstfct(fct_lst);
	if (data)
		free(data);
	return (count);
}
