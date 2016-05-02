#include "../includes/ft_printf.h"



#include <stdio.h>


int		ft_printf_putloct(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned long	res;
	t_lst							*lst;

	res = va_arg(ap, unsigned long);
	lst = 0;
	if (res == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	pow = 1;
	while (pow <= res / 8)
			pow *= 8;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 8;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_putoct(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned int	res;
	int				nb;
	t_lst					*lst;

	lst = 0;
	nb = va_arg(ap, int);
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	else
		res = nb;
	pow = 1;
	while (pow <= res)
		pow *= 8;
	pow /= 8;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 8;
	}
	return (lst_finish(lst, data));
}


int		ft_printf_putptr(t_data *data, va_list ap)
{
	unsigned long	pow;
	unsigned long	res;
	unsigned long	nb;
	t_lst					*lst;

	lst = 0;
	nb = va_arg(ap, unsigned long);
	lst = pushback_lst(lst, '0');
	lst = pushback_lst(lst, 'x');
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	res = nb;
	pow = 1;
	while (res / pow >= 16)
		pow *= 16;
	while (pow)
	{
		if (res / pow < 10)
			pushback_lst(lst, '0' + res / pow);
		else
			pushback_lst(lst, 'a' + res / pow - 10);
		res = res - (res / pow) * pow;
		pow /= 16;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_puthexa(t_data *data, va_list ap)
{
	unsigned int	pow;
	unsigned int	res;
	int				nb;
	t_lst				*lst;

	lst = 0;
	nb = va_arg(ap, int);
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	res = nb;
	pow = 1;
	while (res / pow >= 16)
		pow *= 16;
	while (pow)
	{
		if (res / pow < 10)
			lst = pushback_lst(lst, '0' + res / pow);
		else if (*(data->fmt) == 'x')
			lst = pushback_lst(lst, 'a' + res / pow - 10);
		else
			lst = pushback_lst(lst, 'A' + res / pow - 10);
		res = res - (res / pow) * pow;
		pow /= 16;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_putlhexa(t_data *data, va_list ap)
{
	unsigned long long pow;
	unsigned long	long res;
	t_lst				*lst;

	lst = 0;
	res = va_arg(ap, unsigned long long);
	if (res == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	pow = 1;
	while (res / pow >= 16)
		pow *= 16;
	while (pow)
	{
		if (res / pow < 10)
			lst = pushback_lst(lst, '0' + res / pow);
		else if (*(data->fmt) == 'x')
			lst = pushback_lst(lst, 'a' + res / pow - 10);
		else
			lst = pushback_lst(lst, 'A' + res / pow - 10);
		res = res - (res / pow) * pow;
		pow /= 16;
	}
	return (lst_finish(lst, data));
}
