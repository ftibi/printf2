#include "../includes/ft_printf.h"


t_lst		*two_oct(int c, t_lst *lst)
{
	char *mask;

	//	ft_putendl("2oct");
	mask = ft_strdup("110xxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	lst = print_mask(mask, 2, lst);
	return (lst);
}

t_lst		*three_oct(int c,  t_lst *lst)
{
	char *mask;

	mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	lst = print_mask(mask, 3, lst);

	return (lst);
}

t_lst		*four_oct(int c,  t_lst *lst)
{
	char *mask;

	mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	lst = print_mask(mask, 4, lst);

	return (lst);
}


int		ft_printf_putlstr(t_data *data, va_list ap)
{
	int		count;
	int		*str;
	t_lst	*lst;

	lst = 0;
	str = va_arg(ap, int*);
	if (!str)// || !(*str))
	{
		// ft_putstr("(null)");
		lst = pushback_lst(lst, '(');
		lst = pushback_lst(lst, 'n');
		lst = pushback_lst(lst, 'u');
		lst = pushback_lst(lst, 'l');
		lst = pushback_lst(lst, 'l');
		lst = pushback_lst(lst, ')');
	}
	while (str && *str)
	{
		if (*str < 128)
			lst = pushback_lst(lst, *str);
		else if (*str < 2048)
			lst =  (two_oct(*str, lst));
		else if (*str < ft_pow(2, 15) * 2 - 1)
			lst = three_oct(*str,lst);
		else
			lst = four_oct(*str, lst);
		str++;
	}
	count = lst_finish(lst, data);
	return (count);
}

//coder un char jusqua 4 octets, la limite utf8
int		ft_printf_putlchar(t_data *data, va_list ap)
{
	int		c;
	t_lst *lst;
	int		count;

	lst = 0;
	c = va_arg(ap, int);
	if (c < 128)
		lst = pushback_lst(lst, c);
	else if (c < 2048)
		lst = two_oct(c, lst);
	else if (c < ft_pow(2, 15) * 2 - 1)
		lst = three_oct(c, lst);
	else
		lst = four_oct(c, lst);
	//	return (0);//a retirer
	count = lst_finish(lst, data);
	return (count);
}
