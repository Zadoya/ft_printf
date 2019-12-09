

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int tab[5] = {0, 1, 2, 3, 4};
	char *str = "Hello";
	char c = '\0';
	int i = 0;
	short sh = 5555;
	long long a = -9223372036854775807;
	unsigned long long ull = 18446744073709551615;
	unsigned long ul = -5;
	int y = 1000000;
   	long double f = 1000000000.1435697;
	char *digit = "0000000005";
	int dg = ft_atoi(digit);
	char **ttab = malloc(sizeof(char **) * 5);
	ttab[0] = "AAA";
	ttab[1] = "BBB";
	ttab[2] = "CCC";
	ttab[3] = "DDD";
	ttab[4] = NULL;
	char 	*file = "text";

	float ff = 2.1f;
//	i = printf("Hello %.c %.c %7.6i %.s %#o %#10.10X %.p %i %-+10.3f ===%%%%s %i \n", 'A', c, -589, "***STRING***", *str, 1000, &tab, y, f, 000005);
	i = printf("~~~|%8388609.8388608Lf|~~~\n", f);
	ft_putstr("std printf returns ");
	ft_putnbr(i);
	ft_putchar('\n');


	i = ft_printf("~~~|%f|~~~\n", ff);
	ft_putstr("our ft_printf returns ");
	ft_putnbr(i);
	ft_putchar('\n');




	return 0;
}