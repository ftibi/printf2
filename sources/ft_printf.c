/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:37:25 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/11 15:00:08 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*fmt_read(const char *format, va_list ap, int *count)
{
	if (!(*format))
	{
	//	ft_putchar(' ');
	//	format++;
		return (format);	
	}
	if (*format == ' ')
		format++;
	else if (*format == '%')
	{
		ft_putchar(*format);
		(*count)++;
		format++;
	}
	else if (*format == 'c')
	{
		(*count)++;
		ft_putchar((char)va_arg(ap, int));
		format++;
	}
	else if (*format == 's')
	{
		*count += ft_printf_putstr(va_arg(ap, char*));
		format++;
	}
	else if (*format == 'd' || *format == 'i')
	{
		*count += ft_printf_putnbr(va_arg(ap, int));
		format++;
	}
	else if (*format == 'x')
	{
		*count += ft_printf_puthexa(va_arg(ap, int));
		format++;
	}
	else if (*format == 'p')
	{
		ft_putstr("0x");
		*count += ft_printf_putptr(va_arg(ap, unsigned long));
		format++;
	}
	else
	{
		(*count)++;
		ft_putchar(*format);
		format++;
	}
	return (format);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	t_data		*data;

	count = 0;
	va_start(ap, format);
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
			data = parse_flags(&format);
			format = fmt_read(format, ap, &count);
		}
		//print_flags(data);
	}
	va_end(ap);
	return (count);
}
