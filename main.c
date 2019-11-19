/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:27:53 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/13 15:27:56 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	//int tab[5] = {0, 1, 2, 3, 4};
	char *str = "Hello";
	//char c = '\0';
	int i = 0;
	/*long a = 21;
	int y = 1000000;
	float f = 3.17;
	char *digit = "0000000005";
	int dg = ft_atoi(digit);
*/

//	i = printf("Hello %.c %.c %7.6i %.s %#o %#10.10X %.p %i %-+10.3f ===%%%%s %i \n", 'A', c, -589, "***STRING***", *str, 1000, &tab, y, f, 000005);
	i = printf("~~~|%020s|~~~", *str);
	ft_putstr("std printf returns ");
	ft_putnbr(i);
	ft_putchar('\n');



	/*i = ft_printf("Hello %c %c %i %s %o %X %p %i ===%%%%s %i %i %d\n", 'A', c, -589, "***STRING***", *str, 1000, &tab, y);
	ft_putstr("my ft_printf returns ");
	ft_putnbr(i);
	ft_putchar('\n');*/



	/*printf("%p\n", str);
	printf("%p\n", str + 1);
	printf("%%%%s\n");
	printf("size of tab is %lu\n", sizeof(tab));
	printf("size of str is %lu\n", sizeof(str));
	printf("%s\n", str);
	printf("hello[%c] 42\n", c);*/

	return 0;
}
