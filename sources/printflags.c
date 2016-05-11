#include "../includes/ft_printf.h"

void		print_flags(t_data *new)
{
	if (DEBUG)
		ft_putendl("print flags");
	ft_putstr("hash : ");
	ft_putnbr(new->hash);
	ft_putchar('\n');
	ft_putstr("plus : ");
	ft_putnbr(new->plus);
	ft_putchar('\n');
	ft_putstr("minus : ");
	ft_putnbr(new->minus);
	ft_putchar('\n');
	ft_putstr("0 : ");
	ft_putnbr(new->zero);
	ft_putchar('\n');
	ft_putstr("space : ");
	ft_putnbr(new->space);
	ft_putchar('\n');
	ft_putstr("hh : ");
	ft_putnbr(new->hh);
	ft_putchar('\n');
	ft_putstr("h : ");
	ft_putnbr(new->h);
	ft_putchar('\n');
	ft_putstr("l : ");
	ft_putnbr(new->l);
	ft_putchar('\n');
	ft_putstr("ll : ");
	ft_putnbr(new->ll);
	ft_putchar('\n');
	ft_putstr("j : ");
	ft_putnbr(new->j);
	ft_putchar('\n');
	ft_putstr("z : ");
	ft_putnbr(new->z);
	ft_putchar('\n');
}
