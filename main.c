/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:44:53 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/27 15:57:56 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(int ac, char **av)
 {
// 	int	res;
// //	int ptr = 400;
// 	int a;
// 	int b;
ac++;
av++;
// 	unsigned long i = ULONG_MAX;
// 	char *rev;
//
 //	unsigned char z = UCHAR_MAX + 42;
    int a;
    int b;
//
	a =    printf("built in %#x\n", 0);
	b = ft_printf("ft       %#x\n", 0);

    printf("built in : %d, ft : %d\n", a, b);

	//ft_printf("char : %C \n", i);
//	printf("{%S}", NULL);
//	ft_putendl(str);
//	rev  = ft_strrev(str);
//	ft_putendl(rev);

	//ft_putendl(ft_strchr("#0-+ ", 's'));

//	 ft_printf("Salut comment %s va %s en %d?\n", "ca", "bien", 2016);
//	ft_putnbr(res);
//	ft_putchar('\n');
//
//	ft_printf_putnbr(0);
//	ft_putchar('\n');
//
//	printf("test %s \n", NULL);
//
//	ft_printf("%d%d%d%d%d\n", -1, -2, -3, -4, -5);
//
//	printf("stdio addresse dun pointeur : %p\n", &res);
//	ft_printf("ft addresse dun pointeur : %p\n", &res);
//	printf("stdio 42 en hexa : %x\n", 42);
//	ft_printf("ft 42 en hexa : %x\n", 42);
//	printf("stdio UINTMAX en hexa : %x\n", UINT_MAX);
//	ft_printf("ft UINTMAX en hexa : %x\n", UINT_MAX);
//
//	//printf("% Zoooo\n");
//	//ft_printf("% Zoooo\n");
//
//	int *ptr;
//	ptr = NULL;
//	a = printf("io addresse dun pointeur : %p\n", ptr);
//	b = ft_printf("ft addresse dun pointeur : %p\n", ptr);
//	printf(" a = %d, b = %d \n", a, b);
//
//
//	a = printf("io %");
//	ft_putchar('\n');
	 //ft_printf("%lh+j0");
//	ft_putchar('\n');
//	printf(" a = %d, b = %d \n", a, b);



	return (0);
}
