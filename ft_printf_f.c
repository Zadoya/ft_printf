#include "ft_printf.h"

int		f(t_specifications *data, va_list *ap)
{
	if (data->dot == 0)
		ft_putstr(floatToString(va_arg(*ap, double), 6));
	else if (data->dot > 0 && data->precision == 0)
		ft_putstr(floatToString(va_arg(*ap, double), 0));
	else if (data->dot > 0 && data->precision > 0)
		ft_putstr(floatToString(va_arg(*ap, double), data->precision));
	return(0);
}