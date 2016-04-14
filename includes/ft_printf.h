/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:34:56 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/14 15:53:27 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# define DEBUG 0

typedef int(*ft_function)(void*, void*);

int		ft_printf(const char *format, ...);

typedef struct		s_fct
{
	char			conv;
	void			*fct;
	struct s_fct	*next;

}					t_fct;
//t_fct				*add_fct(t_fct *start, void *fct, char conv);
void				*get_fct(t_fct *start, char conv);
t_fct				*fct_init(void);

typedef struct	s_data
{
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			mwidth; //largeur mini
	int			precision;
	char		*fmt;
}				t_data;

t_data	*parse_flags(const char **fmt);
t_data	*new_data(void);

void	print_flags(t_data *data);

int		ft_printf_putstr(char *str, t_data *data);
int		ft_printf_putnbr(int nb, t_data *data);
int		ft_printf_puthexa(int nb, t_data *data);
int		ft_printf_putptr(unsigned long nb, t_data *data);

#endif
