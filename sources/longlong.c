#include "../includes/ft_printf.h"

int		ft_printf_putlloct(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned long	long res;
	t_lst							*lst;

	res = va_arg(ap, unsigned long long);
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

int		ft_printf_putllhexa(t_data *data, va_list ap)
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

int		ft_printf_putllunbr(t_data *data, va_list ap)
{
	unsigned  long long	pow;
	unsigned  long	long res;
	unsigned  long	long nb;
	t_lst						*lst;

	lst = 0;
	nb = va_arg(ap, unsigned long long);
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	res = nb;
	pow = 1;
	while (pow <= res / 10)
		pow *= 10;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 10;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_putllnbr(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned long	long res;
	long long				nb;
	t_lst						*lst;

	lst = 0;
	nb = va_arg(ap, long long);
	if (nb == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	if (nb < 0)
	{
		res = -nb;
		lst = pushback_lst(lst, '-');
	}
	else
		res = nb;
	pow = 1;
	while (pow <= res)
		pow *= 10;
	pow /= 10;
	while (pow)
	{
		lst = pushback_lst(lst, '0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 10;
	}
	return (lst_finish(lst, data));
}
