#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i;
	long long int j = 73458;

	i = ft_printf("~~~|%-0#+5.65c|~~~\n", 'd');
	//i = printf("%-10hhhohhhd",j);
	printf("%d", i);
	return(0);
}