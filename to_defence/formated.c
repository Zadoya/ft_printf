/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formated.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:10:17 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/28 14:10:20 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_istype(char c)
{
	char		*type;
	int			i;

	i = 0;
	type = "dioxXucsSBTeEygGpnf%";
	while (type[i])
	{
		if (type[i] == c)
			return (type[i]);
		i++;
	}
	return (0);
}

static char		ft_isflag(char c)
{
	char		*flags;
	int			i;

	i = 0;
	flags = "#0-+ ";
	while (flags[i])
	{
		if (flags[i] == c)
			return ((char)i);
		i++;
	}
	return (-1);
}

static int		in_case_of_alfa(char **str, t_specifications *fmt)
{
	int			i;

	if (**str == 'r' || **str == 'y' || **str == 'b')
		add_colour(fmt, **str);
	else if (!ft_strncmp(*str, "ll", 2) || !ft_strncmp(*str, "hh", 2))
	{
		fmt->sign[0] = **str;
		fmt->sign[1] = *(*str + 1);
		return (1);
	}
	else if ((**str == 'l' || **str == 'h' || **str == 'L') &&
				fmt->sign[0] != 'l' && fmt->sign[0] != 'h')
	{
		fmt->sign[0] = **str;
		fmt->sign[1] = 0;
		return (1);
	}
	else if (ft_istype(**str))
	{
		i = 0;
		while (fmt->sign[i])
			i++;
		fmt->sign[i] = **str;
		return (1);
	}
	return (0);
}

static void		in_case_of_digit(int dot, char **str, t_specifications *fmt)
{
	if (dot == 0)
	{
		fmt->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	else
	{
		fmt->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	(*str)--;
}

char			*formated(char **string, t_specifications *fmt)
{
	int			dot;
	char		*str;

	dot = 0;
	str = *string;
	while (*str)
	{
		if (ft_isalpha(*str) || *str == '%')
		{
			if (!in_case_of_alfa(&str, fmt))
				return (str);
		}
		else if (*str == '.')
		{
			if (in_case_of_dot(&dot, fmt))
				return (0);
		}
		else if (ft_isdigit(*str) && *str != '0')
			in_case_of_digit(dot, &str, fmt);
		else if ((fmt->in = ft_isflag(*str)) >= 0 && fmt->flag[fmt->in] == 0)
			fmt->flag[fmt->in] = *str;
		str++;
	}
	string = &str;
	return (0);
}
