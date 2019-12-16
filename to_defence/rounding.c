/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:06:17 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/14 17:06:23 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*from_two_digits_to_one(char *result)
{
	int				result_digit;

	result_digit = (int)(ft_strlen(result) - 1);
	while (result_digit >= 0)
	{
		if (result[result_digit] != '.')
		{
			while (result[result_digit] > '9')
			{
				result[result_digit] -= 10;
				if (result[result_digit - 1] == '.')
					result[result_digit - 2] += 1;
				else if (result_digit == 0)
				{
					result = ft_concat_and_free("1", result);
					result_digit++;
				}
				else
					result[result_digit - 1] += 1;
			}
		}
		result_digit--;
	}
	return (result);
}

static void			in_case_of_big_num(char *result)
{
	int				i;
	char			*tmp;
	char			*tmp2;

	tmp = result;
	i = 0;
	while (i != 18)
	{
		if (*tmp != '.')
			i++;
		tmp++;
	}
	tmp2 = tmp + 1;
	while (*tmp2 == '5' || *tmp2 == '.')
		tmp2++;
	*tmp2 > '5' ? (*tmp)++ : *tmp;
	tmp++;
	while (*tmp)
	{
		if (*tmp != '.')
			*tmp = '0';
		tmp++;
	}
}

static void			in_case_of_small_num(char *result)
{
	int				i;
	char			*tmp;
	char			*tmp2;
	int				num_indicator;

	tmp = result + 2;
	i = 0;
	num_indicator = 0;
	while (i++ != 22)
	{
		if (*tmp != '0')
			num_indicator++;
		tmp++;
	}
	if (num_indicator == 0)
		while (*tmp == '0')
			tmp++;
	tmp2 = tmp + 1;
	while (*tmp2 == '5' || *tmp2 == '.')
		tmp2++;
	*tmp2 > '5' ? (*tmp)++ : *tmp;
	tmp++;
	while (*tmp)
		*(tmp++) = '0';
}

char				*rounding(char *result, t_specifications *data)
{
	char			*rounded_result;
	int				i;
	char			*tmp;
	char			*tmp2;

	tmp = result;
	i = data->precision;
	while (*tmp != '.')
		tmp++;
	if (*result == '0')
		in_case_of_small_num(result);
	else
		in_case_of_big_num(result);
	while (i-- > 0)
		tmp++;
	tmp2 = tmp + 1;
	while (*tmp2 == '5')
		tmp2++;
	if (*tmp == '.')
		tmp--;
	*tmp2 > '5' ? (*tmp)++ : *tmp;
	rounded_result = ft_strsub(result, 0, tmp - result + 1);
	rounded_result = from_two_digits_to_one(rounded_result);
	free(result);
	return (rounded_result);
}
