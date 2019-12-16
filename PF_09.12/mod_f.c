/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:23:02 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/04 19:23:05 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char				*float_to_str(union u_long_double	*a, t_specifications *data)
{
	unsigned long 		mantissa;
	int					exponent;
	char 				*result;

	mantissa = a->s_parts_of_ld.m;
	exponent = a->s_parts_of_ld.e - 16383;
	result = divide_m(mantissa, data);

	char *m = ft_ulltoa_base(mantissa, 10);
	char *e = ft_itoa_base(exponent, 10);
	ft_putstr("mantissa is: ");
	ft_putstr(m);
	ft_putchar('\t');
	ft_putstr("exponent is: ");
	ft_putstr(e);
	ft_putchar('\t');
//	if (exponent >= 0)
//		result = multiplication(result, 1 << exponent);
//	else
		result = divizion(result, data, 1 << -exponent);

	ft_putstr(result);
	return (result);

	ft_putstr("mantissa is: ");
	ft_putstr(m);
	ft_putchar('\t');
	ft_putstr("exponent is: ");
	ft_putstr(e);
	ft_putchar('\t');
	ft_putstr("sign is: ");
	a->s_parts_of_ld.s << 1 == 0 ?	ft_putchar('+') : ft_putchar('-');
	ft_putchar('\n');
	ft_putstr(result);
	return (result);
}

int						mod_f(t_specifications *data, va_list *ap)
{
	int					result;
	union u_long_double	a;
	char				*str;

	result = 0;
	a.ld = va_arg(*ap, long double);
	str = float_to_str(&a, data);








	close_colour(data);
	return (result);
}








/*
ft_putstr("\n\nmantissa is: ");
ft_putstr(ft_ulltoa_base(mantissa, 10));
ft_putchar('\t');
ft_putstr("exponent is: ");
ft_putstr(ft_ulltoa_base(exponent, 10));


*/


/*struct {
		unsigned int is_keyword : 8;
		unsigned int is_extern : 8;
		unsigned int is_static : 8;
		unsigned int is_externe : 8;

	} flags;



	ft_putstr("\n***|");
	ft_putnbr(sizeof(flags));
	ft_putstr("|***\n");*/












/*
	long double		*pld;

	int				i;
	unsigned char	*c;
	int 			*ptr;

	float			drob;
	float			*dptr;

	i = 255;
	ptr = &i;
	c = (unsigned char *)ptr;
	result = 0;

	drob = 255;
	dptr = &drob;
	c = (unsigned char *)dptr;
*/

/* 4    00000000 00000000 01111111 01000011
 * 8	00000000 00000000 00000000 00000000 00000000 11100000 01101111 01000000
 * 16   00000000 00000000 00000000 00000000 00000000 00000000 00000000 11111111 00000110 01000000 11111000 00001001 00010010 00000000 00000000 00000000
 * 16L  00000000 00000000 00000000 00000000 00000000 00000000 00000000 11111111 00000110 01000000 11111100 00001000 00010010 00000000 00000000 00000000
 *
 *
 * */

	/*num = va_arg(*ap, long double);
	pld = &num;*/
	//c = (unsigned char *)ptr;

/*
	ft_putstr("\n\n\n");
	//ft_putnbr(*ptr);
	ft_putnbr(sizeof(long double));
	ft_putchar('\t');
	while (result++ < 4)
	{
		ft_printbits(*(c++));
		ft_putchar(' ');
	}
	ft_putstr("\n\n\n");
*/
