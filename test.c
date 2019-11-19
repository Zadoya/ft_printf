#include "libft/libft.h"
#include <stdio.h>

int 	main(void)
{
	int num = 100;
	int base = 10;
	ft_putstr("start\n");
	char *arr = ft_itoa_base(num, base);
	ft_putstr(arr);
	return (0);
}