#include "../includes/ft_printf.h"

int		ft_printf_putstr(t_data *data, va_list ap)
{
	char	*str;
	t_lst *lst;

	str = va_arg(ap, char*);
	lst = 0;
	if (!str)
	{
		lst = pushback_lst(lst, '(');
		lst = pushback_lst(lst, 'n');
		lst = pushback_lst(lst, 'u');
		lst = pushback_lst(lst, 'l');
		lst = pushback_lst(lst, 'l');
		lst = pushback_lst(lst, ')');
	}
	while (str && *str)
	{
		lst = pushback_lst(lst, *str);
		str++;
	}
	return (lst_finish(lst, data));
}

int		ft_printf_putchar(t_data *data, va_list ap)
{
	t_lst	*lst;
	char	c;

	lst = 0;
	c = va_arg(ap, int);
	lst = pushback_lst(lst, c);
	return (lst_finish(lst, data));
}
