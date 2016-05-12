/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:34:52 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/10 15:03:49 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_stock		*check_fd(const int fd, t_stock *stock, t_stock **save)
{
	if (!stock)
	{
		if (!(stock = (t_stock*)malloc(sizeof(t_stock))))
			return (NULL);
		stock->fd = fd;
		stock->str = ft_strdup("");
		stock->status = 1;
		stock->next = NULL;
		*save = stock;
		return (stock);
	}
	while ((stock->fd != fd) && stock->next)
		stock = stock->next;
	if (stock->fd != fd)
	{
		if (!(stock->next = (t_stock*)ft_memalloc(sizeof(t_stock))))
			return (NULL);
		stock = stock->next;
		stock->fd = fd;
		stock->str = ft_strdup("");
		stock->status = 1;
		stock->next = NULL;
	}
	return (stock);
}

static int			delstock(int fd, t_stock *stock)
{
	t_stock	*save;

	if (!stock)
		return (0);
	save = stock;
	while (stock && stock->next)
	{
		if (stock->fd == fd)
		{
			save->next = stock->next;
			if (stock->str)
				ft_memdel((void**)&(stock->str));
			ft_memdel((void**)&stock);
			stock = save->next;
			return (1);
		}
		else
		{
			save = stock;
			stock = stock->next;
		}
	}
	return (0);
}

static int			bufcpy(char **line, t_stock *stock, t_stock *stock_save)
{
	int		n;
	char	*save;
	char	*tmp;

	tmp = stock->str;
	n = (int)(ft_strchr(tmp, '\n') - tmp);
	n = ((unsigned int)n > ft_strlen(tmp) + 1) ? ft_strlen(tmp) : n;
	*line = ft_strndup(tmp, n);
	save = tmp;
	tmp += n + 1;
	tmp = ft_strdup(tmp);
	stock->str = tmp;
	if (!ft_strlen(tmp) && !stock->status)
	{
		delstock(stock->fd, stock_save);
		return (0);
	}
	return (1);
}

static int			fill_tmp(t_stock *stock)
{
	char	*tmp;
	char	buf[BUFF_SIZE];
	int		nbr;
	char	*save;

	nbr = BUFF_SIZE;
	tmp = stock->str;
	while ((!ft_strchr(tmp, '\n') || nbr == 0) && nbr == BUFF_SIZE)
	{
		ft_memset(buf, 0, BUFF_SIZE);
		if ((nbr = read(stock->fd, buf, BUFF_SIZE)) == -1)
			return (nbr);
		if (nbr < BUFF_SIZE)
			stock->status = 0;
		save = tmp;
		if (!(tmp = (char*)ft_memalloc(ft_strlen(tmp) + BUFF_SIZE + 1)))
			return (-1);
		tmp = ft_strcpy(tmp, save);
		tmp = ft_strncat(tmp, (const char*)buf, BUFF_SIZE);
		if (save)
			ft_memdel((void**)&save);
		stock->str = tmp;
	}
	return ((nbr <= 0) ? nbr : 1);
}

int					get_next_line(int const fd, char **line)
{
	t_stock			*stock;
	static t_stock	*save;

	if (!line)
		return (-1);
	stock = save;
	if (!(stock = check_fd(fd, stock, &save)))
		return (-1);
	if (!(ft_strchr(stock->str, '\n')))
		stock->status = fill_tmp(stock);
	if (stock->status == -1)
		return (stock->status);
	stock->status = bufcpy(line, stock, save);
	return (stock->status);
}
