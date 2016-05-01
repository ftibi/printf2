#include "../includes/ft_printf.h"

int		ft_printf_putloct(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned long	res;
	int				count;
	unsigned long			nb;

	nb = va_arg(ap, unsigned long);
	data->mwidth = 1; //a retirer, c juste pour utiliser data
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
		res = nb;
	pow = 1;
	while (pow <= res)
		pow *= 8;
	pow /= 8;
	while (pow)
	{
		ft_putchar('0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 8;
		count++;
	}
	return (count);
}

int		ft_printf_putoct(t_data *data, va_list ap)
{
	unsigned long long	pow;
	unsigned int	res;
	int				count;
	int				nb;

	nb = va_arg(ap, int);
	data->mwidth = 1; //a retirer, c juste pour utiliser data
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
		res = nb;
	pow = 1;
	while (pow <= res)
		pow *= 8;
	pow /= 8;
	while (pow)
	{
		ft_putchar('0' + res / pow);
		res = res - (res / pow) * pow;
		pow /= 8;
		count++;
	}
	return (count);
}


int		ft_printf_putptr(t_data *data, va_list ap)
{
	unsigned long	pow;
	unsigned long	res;
	int				count;
	unsigned long	nb;

	data->mwidth = 1; //a retirer, c juste pour utiliser data
	count = 2;

	nb = va_arg(ap, unsigned long);
	if (nb == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	res = nb;
	pow = 1;
	while (res / pow >= 16)
		pow *= 16;
	while (pow)
	{
		if (res / pow < 10)
			ft_putchar('0' + res / pow);
		else
			ft_putchar('a' + res / pow - 10);
		res = res - (res / pow) * pow;
		pow /= 16;
		count++;
	}
	return (count);
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
