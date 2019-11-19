#include "ft_printf.h"
#include "libft/libft.h"

char	ft_istype(char c)
{
	char	type[] = "dioxXucsfeEgGpnf%";
	int		i;
	
	i = 0;
	while (type[i])
	{
		if (type[i] == c)
			return (type[i]);
		i++;
	}
	return(0);
}

char	ft_isflag(char c)
{
	char	flags[] = "#0-+ ";
	int		i;
	
	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (i);
		i++;
	}
	return(-1);
}

int		formated(char **string, t_specifications *fmt)
{	
	int		i;
	char	dot;
	char	*str;

	dot = 0;
	str = *string;
	while (str)
	{
		if (ft_isalpha(*str))
		{
			if (!ft_strncmp(str, "ll", 2) || !ft_strncmp(str, "hh", 2))
			{
				fmt->sign[0] = *str;
				fmt->sign[1] = *++str;
			}
			else if (*str == 'l' || *str == 'h')
			{
				fmt->sign[0] = *str;
				fmt->sign[1] = 0;
			}
			else if (ft_istype(*str))
			{
				i = 0;
				while(fmt->sign[i])
					i++;
				fmt->sign[i] = *str;
				break;
			}
		}
		else if (*str == '.')
		{
			if (dot == 0)
				dot++;
			else
				return (1);
		}
		else if (ft_isdigit(*str) && *str != '0')
		{
			if (dot == 0)
			{
				fmt->width = ft_atoi(str);
				while (ft_isdigit(*str))
					str++;
			}
			else
			{
				fmt->precision = ft_atoi(str);
				while (ft_isdigit(*str))
					str++;
			}
			str--;
		}
		else if ((i = ft_isflag(*str)) >=0 && fmt->flag[i] == 0)
			fmt->flag[i] = *str;
		str++;
	}
	*string = str;
	return (1);
}

int            mod_c(t_specifications *data, va_list *ap)
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

int		ft_printf(char *format, ...)
{
    va_list				arg_ptr;
    int					quantity;
    char				*str;
    t_specifications 	fmt;

	str = format;
    va_start(arg_ptr, format);   // установил указтель на 1-ый аргумент
	quantity = 0;
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			quantity++;
		}
		else
		{
			ft_bzero(fmt.flag, 6);
			ft_bzero(fmt.sign, 4);
			fmt.precision = 0;
			fmt.width = 0;
			str++;	
			if (formated(&str, &fmt))
				quantity += mod_c(&fmt, &arg_ptr);
		}
		str++;
	}
    va_end(arg_ptr);
    return(quantity);
}