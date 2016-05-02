#include "../includes/ft_printf.h"

int		ft_printf_puthhnbr(t_data *data, va_list ap)
{
	unsigned char	pow;
	unsigned char	res;
	char				nb;
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
