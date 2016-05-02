#include "../includes/ft_printf.h"

int		ft_printf_puthhnbr(t_data *data, va_list ap)
{
	unsigned char	pow;
	unsigned char	res;
	char						nb;
	t_lst			*lst;

	lst = 0;
	nb = va_arg(ap, int);
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

int		ft_printf_putuhhnbr(t_data *data, va_list ap)
{
	unsigned char	pow;
	unsigned char	res;
	t_lst			*lst;

	lst = 0;
	res = va_arg(ap, int);
	if (res == 0)
	{
			lst = pushback_lst(lst, '0');
			return (lst_finish(lst, data));
	}
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

int		ft_printf_puthhoct(t_data *data, va_list ap)
{
	unsigned int	pow;
	unsigned char	res;
	t_lst					*lst;

	lst = 0;
	res = va_arg(ap, int);
	if (res == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
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


int		ft_printf_puthhhexa(t_data *data, va_list ap)
{
	unsigned int	pow;
	unsigned char	res;
	t_lst				*lst;

	lst = 0;
	res = va_arg(ap, int);
	if (res == 0)
	{
		lst = pushback_lst(lst, '0');
		return (lst_finish(lst, data));
	}
	pow = 1;
	while (pow <= res / 16)
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
