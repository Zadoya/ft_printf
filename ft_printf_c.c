#include "ft_printf.h"

int		c(t_specifications *data, va_list *ap)
{
    char     c;
    int     result;

    if (data->width > 1)
        result = data->width;
    else
        result = 1;
    c = va_arg(*ap, int);
    if (data->flag[2] == '-')
    {
        ft_putchar(c);
        while ((data->width)-- > 1)
            ft_putchar(' ');
    }
    else
    {
        while ((data->width)-- > 1)
            ft_putchar(' ');
        ft_putchar(c);
    }
    return (result);
}
