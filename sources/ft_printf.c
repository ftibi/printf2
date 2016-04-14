/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:37:25 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/14 14:23:24 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*fmt_read(t_data *data, va_list ap, int *count, t_fct *fct_lst)
{
	void	*fct;
	char 	*format = data->fmt;
	if (!(*format))
	{
	//	ft_putchar(' ');
	//	format++;
		return (format);	
	}
	if (*format == ' ')
		format++;
	fct = get_fct(fct_lst, *format);
	if (!fct)
	{
		ft_putchar(*format);
		format++;
		(*count)++;
		return (format);
	}
	else
		(*count) += fct(data, ap);
	format++;
	return (format);


//	else if (*format == '%')
//	{
//		ft_putchar(*format);
//		(*count)++;
//		format++;
//	}
//	else if (*format == 'c')
//	{
//		(*count)++;
//		ft_putchar((char)va_arg(ap, int));
//		format++;
//	}
//	else if (*format == 's')
//	{
//		*count += ft_printf_putstr(va_arg(ap, char*));
//		format++;
//	}
//	else if (*format == 'd' || *format == 'i')
//	{
//		*count += ft_printf_putnbr(va_arg(ap, int));
//		format++;
//	}
//	else if (*format == 'x')
//	{
//		*count += ft_printf_puthexa(va_arg(ap, int));
//		format++;
//	}
//	else if (*format == 'p')
//	{
//		ft_putstr("0x");
//*count += ft_printf_putptr(va_arg(ap, unsigned long));
//		format++;
//	}
//	else
//	{
//		(*count)++;
//		ft_putchar(*format);
//		format++;
//	}
//	return (format);
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
			data->fmt = (char*)format; //je peux faire ca dans parse flags
			format = fmt_read(data, ap, &count, fct_lst);
		}
		//print_flags(data);
	}
	va_end(ap);
	return (count);
}
