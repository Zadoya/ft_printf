/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:25:52 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/09 13:25:56 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*minus_dec(char *m, int len_m)
{
	if (m[len_m - 1] == '0')
		minus_dec(m, len_m - 1);
	m[len_m - 1] -= 1;
	m[len_m] += 10;
	return (m);
}

static char 	*substraction(char *m, char *second_arg)
{
	int 		len_m;
	int 		len_second;

	len_m = ft_strlen(m) - 1;
	len_second = ft_strlen(second_arg) - 1;
	while (len_second >= 0)
	{
		if(m[len_m] < second_arg[len_second])
			m = minus_dec(m, len_m);
		m[len_m] = m[len_m] - second_arg[len_second--] + '0';
		len_m--;
	}
	while (*m == '0')
		m++;
	return (m);
}

static char		circle_substraction(char *m, char *second_arg)
{
	char		result;

	result = 0;
	if (*m == '0')
		m++;
	while ((ft_strlen(m) > 19) || (ft_strcmp(m, second_arg) >= 0))
	{
		m = substraction(m, second_arg);
		result++;
	}
	return (result + '0');
}


static void 	move_mantissa(char *m, char *second_arg, char *result, int *i)
{
	char 		*tmp;
	char 		*tmp2;
	char 		*tmp3;
	char		*tmp_res;

	tmp = m;
	tmp2 = m + 1;
	tmp_res = tmp2;
	while (*tmp == '0')
		tmp++;
	tmp3 = tmp;
	while (*(tmp3 + 1) != '\0')
		tmp3++;
	tmp2 = ft_memcpy(tmp2, tmp, tmp3 - tmp);
	if (tmp != tmp2)
	{
		while (tmp_res++ != tmp)
			result[(*i)++] = '0';
	}
	if (tmp3 - tmp > tmp - tmp2)
		tmp = tmp2 + (tmp3 - tmp);
	while (*tmp)
		*tmp++ = '0';
	if (ft_strcmp(tmp2, second_arg) < 0)
		m = ft_memcpy(m, tmp2,tmp3 - tmp2);
}

char 			*divide_m(unsigned long long mantissa, t_specifications *data)
{
	char 		*result;
	int 		i;
	char 		*m;
	char 		*tmp;

	i = 0;
	if (!(result = malloc(data->precision + 22 + 31)))
		return (NULL);
	result[data->precision + 22 + 31] = '\0';
	result[i++] = '1';
	result[i++] = '.';
	m = ft_ulltoa_base(mantissa - 9223372036854775808, 10);
	m = ft_concat_and_freehead(m, "0");
	while (i < data->precision + 22 + 31)
	{
		result[i++] = circle_substraction(m, "9223372036854775808");
		move_mantissa(m, "9223372036854775808", result, &i);
	}
	return (result);
}
