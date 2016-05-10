#include "../includes/ft_printf.h"


int		two_oct(int c, t_data *data)
{
	char *mask;
	int count;

	//	ft_putendl("2oct");
	mask = ft_strdup("110xxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	count = print_mask(mask, 2, data);
	return (count);
}

int		three_oct(int c, t_data *data)
{
	char *mask;
	int count;

	mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	count = print_mask(mask, 3, data);

	return (count);
}

int		four_oct(int c, t_data *data)
{
	char *mask;
	int count;

	mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	mask = fill_mask(mask, c);
	count = print_mask(mask, 4, data);

	return (count);
}


int		ft_printf_putlstr(t_data *data, va_list ap)
{
	int		count;
	int		*str;

	data->mwidth = 1;
	str = va_arg(ap, int*);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = 0;
	while (*str)
	{
		if (*str < 128)
		{
			ft_putchar(*str);
			count++;
		}
		else if (*str < 2048)
			count +=  (two_oct(*str, data));
		else if (*str < ft_pow(2, 15) * 2 - 1)
			count += three_oct(*str, data);
		else
			count += four_oct(*str, data);
		str++;
	}
	return (count);
}

//coder un char jusqua 4 octets, la limite utf8
int		ft_printf_putlchar(t_data *data, va_list ap)
{
	int		c;

	data->mwidth = 1;
	c = va_arg(ap, int);
	if (c < 128)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c < 2048)
		return (two_oct(c, data));
	else if (c < ft_pow(2, 15) * 2 - 1)
		return (three_oct(c, data));
	else
		return (four_oct(c, data));
	//	return (0);//a retirer
}
