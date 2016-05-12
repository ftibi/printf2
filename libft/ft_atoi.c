/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:37:41 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 16:05:09 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*go_start(char const *str)
{
	while (*str == ' ' || *str == '\n' || *str == '	' || *str == '\v' ||
			*str == '\f' || *str == '\r')
	{
		str++;
	}
	return ((char*)str);
}

static int		valid_sign(char *str)
{
	int sign;
	int valid;

	valid = 0;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		sign = (*str == '+') ? 1 : -1;
		valid++;
		str++;
	}
	if (valid > 1)
	{
		return (0);
	}
	return (sign);
}

static char		*after_sign(char *str)
{
	while (*str == '+' || *str == '-')
	{
		str++;
	}
	return (str);
}

int				ft_atoi(const char *str)
{
	char	*parse;
	int		signe;
	int		res;
	int		signechar;

	signechar = 0;
	res = 0;
	parse = go_start(str);
	signe = valid_sign(parse);
	parse = after_sign(parse);
	while (ft_isdigit(*parse))
	{
		res *= 10;
		res += (int)*parse - '0';
		parse++;
	}
	return (signe * res);
}
