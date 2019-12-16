/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiolication_m_by_e.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:34:02 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/10 17:34:04 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*from_two_digits_to_one(unsigned char *result)
{
	int					result_digit;

	result_digit = (int)(ft_strlen((char *)result)) - 1;
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
					result = (unsigned char *)ft_concat_and_free("1",
							(char *)result);
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

static unsigned char	*addition(unsigned char *previous_sum,
									unsigned char *current_result)
{
	int					prev_sum_digit;
	int					sum_digit;
	unsigned char		*sum;

	sum = (unsigned char *)ft_strdup((char *)current_result);
	prev_sum_digit = (int)ft_strlen((char *)previous_sum) - 1;
	sum_digit = (int)ft_strlen((char *)current_result) - 1;
	while (sum_digit >= 0)
	{
		if (prev_sum_digit == 0 && sum_digit)
		{
			previous_sum = (unsigned char *)ft_concat_and_free("0",
														(char *)previous_sum);
			prev_sum_digit++;
		}
		if (sum[sum_digit] != '.')
			sum[sum_digit] = (sum[sum_digit] - '0') +
								(previous_sum[prev_sum_digit] - '0') + '0';
		prev_sum_digit--;
		sum_digit--;
	}
	sum = from_two_digits_to_one(sum);
	free(previous_sum);
	return (sum);
}

static unsigned char	*multiplication_by_digit(char *mantissa,
											unsigned int exp_digit, int decimal)
{
	unsigned char		*result_digit;
	unsigned char		*result;
	char				*dot;

	result = (unsigned char *)ft_strdup(mantissa);
	result_digit = &result[ft_strlen((char *)result) - 1];
	while (result_digit >= result)
	{
		if (*result_digit != '.')
			*result_digit = ((*result_digit - '0') * exp_digit) + '0';
		result_digit--;
	}
	result = from_two_digits_to_one(result);
	while (decimal)
	{
		dot = ft_strchr((char *)result, '.');
		ft_swap(dot, dot + 1);
		result = (unsigned char *)ft_concat_and_freehead((char *)result, "0");
		decimal--;
	}
	return (result);
}

static unsigned char	*lets_multiply(char *mantissa, unsigned char *exponent)
{
	unsigned char		*final_result;
	unsigned char		*exp_digit;
	unsigned char		*current_result;
	int					decimal;

	final_result = NULL;
	decimal = 0;
	exp_digit = &exponent[ft_strlen((char *)exponent) - 1];
	while (exp_digit >= exponent)
	{
		current_result = multiplication_by_digit(mantissa,
							*exp_digit - '0', decimal);
		if (!final_result)
			final_result = (unsigned char *)ft_strdup((char *)current_result);
		else
			final_result = addition(final_result, current_result);
		free(current_result);
		decimal++;
		exp_digit--;
	}
	return (final_result);
}

char					*multiplication(char *mantissa, unsigned int exponent)
{
	unsigned char		*result;
	unsigned char		*tmp;
	unsigned char		current_result;

	if (exponent == 0)
		return (mantissa);
	tmp = exponent_to_str(exponent);
	result = lets_multiply(mantissa, tmp);
	free(tmp);
	free(mantissa);
	return ((char *)result);
}
