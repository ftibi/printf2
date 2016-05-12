/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:34:56 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/28 16:41:39 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# define DEBUG 0

typedef int			(*t_ft_function)(void*, void*);

int					ft_printf(const char *format, ...);

typedef struct		s_fct
{
	char			conv;
	void			*fct;
	struct s_fct	*next;

}					t_fct;
void				ft_error(int nb);

typedef struct		s_data
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
	int			mwidth;
	int			precision;
	char		*fmt;
}					t_data;

t_fct				*fct_init(void);
void				*get_fct(t_fct *start, char conv, t_data *data);
t_data				*new_data(void);
t_data				*parse_flags(char **fmt);
char				*parse_opt_flags(char *format, t_data *data);
char				*parse_mwidth_flag(char *format, t_data *data);
char				*parse_prec_flag(char *format, t_data *data);
char				*parse_jzh_flags(char *format, t_data *data);

void				print_flags(t_data *data);

int					ft_printf_putstr(t_data *data, va_list ap);
int					ft_printf_putlstr(t_data *data, va_list ap);
int					ft_printf_putuhhnbr(t_data *data, va_list ap);
int					ft_printf_puthhnbr(t_data *data, va_list ap);
int					ft_printf_puthnbr(t_data *data, va_list ap);
int					ft_printf_putnbr(t_data *data, va_list ap);
int					ft_printf_putunbr(t_data *data, va_list ap);
int					ft_printf_putlunbr(t_data *data, va_list ap);
int					ft_printf_putllunbr(t_data *data, va_list ap);
int					ft_printf_putlnbr(t_data *data, va_list ap);
int					ft_printf_putllnbr(t_data *data, va_list ap);
int					ft_printf_puthhhexa(t_data *data, va_list ap);
int					ft_printf_puthexa(t_data *data, va_list ap);
int					ft_printf_putlhexa(t_data *data, va_list ap);
int					ft_printf_putllhexa(t_data *data, va_list ap);
int					ft_printf_putptr(t_data *data, va_list ap);
int					ft_printf_putchar(t_data *data, va_list ap);
int					ft_printf_puthhoct(t_data *data, va_list ap);
int					ft_printf_puthoct(t_data *data, va_list ap);
int					ft_printf_putoct(t_data *data, va_list ap);
int					ft_printf_putloct(t_data *data, va_list ap);
int					ft_printf_putlloct(t_data *data, va_list ap);
int					ft_printf_putlchar(t_data *data, va_list ap);

t_fct				*add_fct(t_fct *start, void *fct, char conv);
t_fct				*new_fct(void *fct, char conv);

t_data				*data_mod(t_data *data);
typedef struct		s_lst
{
	char			c;
	struct s_lst	*next;
}					t_lst;

t_lst				*print_mask(char *mask, int oct, t_lst *lst);
char				*fill_mask(char *mask, int c);
char				*ft_strrev(char *str);

t_lst				*new_lst(char c);
t_lst				*pushback_lst(t_lst *lst, char c);
t_lst				*pushfront_lst(t_lst *lst, char c);
t_lst				*lst_null(t_lst *lst);
int					lst_len(t_lst *lst);
int					lst_digit(t_lst *lst);
int					lst_sum_digit(t_lst *lst);
int					lst_sum_alnum(t_lst *lst);
t_lst				*del_all_digits(t_lst *lst);
void				print_lst(t_lst *lst);
void				free_lst(t_lst *lst);
t_lst				*format_lst(t_lst *lst, t_data *data);
t_lst				*hashfmt(t_lst *lst, t_data *data);
t_lst				*mwidthfmt(t_lst *lst, t_data *data);
t_lst				*plusfmt(t_lst *lst, t_data *data);
t_lst				*precisionfmt(t_lst *lst, t_data *data);
t_lst				*spacefmt(t_lst *lst, t_data *data);
int					lst_finish(t_lst *lst, t_data *data);

#endif
