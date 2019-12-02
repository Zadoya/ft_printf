#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i;
	double j = 73487678654768911118.6576467;
	double f = 1.11111111;

	i = ft_printf("~~~|%5.29lf|~~~\n", j);
	printf("~~~|%5.29lf|~~~\n", j);
	//i = printf("%-10hhhohhhd",j);
	printf("%d", i);
	return(0);
}