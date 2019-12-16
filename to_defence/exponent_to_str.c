/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exponent_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:50:53 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/13 15:50:56 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*from_two_digits_to_one(unsigned char *result)
{
	int					result_digit;

	result_digit = (int)(ft_strlen((char *)result)) - 1;
	while (result_digit >= 0)
	{
		while (result[result_digit] > '9')
		{
			result[result_digit] -= 10;
			if (result_digit == 0)
			{
				result = (unsigned char *)ft_concat_and_free("1",
						(char *)result);
				result_digit++;
			}
			else
				result[result_digit - 1] += 1;
		}
		result_digit--;
	}
	return (result);
}

static unsigned char	*addition(unsigned char *first_term,
									unsigned char *second_term)
{
	int					second_term_digit;
	int					sum_digit;
	unsigned char		*sum;

	sum = (unsigned char *)ft_strdup((char *)first_term);
	sum_digit = (int)ft_strlen((char *)first_term) - 1;
	second_term_digit = (int)ft_strlen((char *)second_term) - 1;
	while (sum_digit < second_term_digit)
	{
		sum = (unsigned char *)ft_concat_and_free("0", (char *)sum);
		sum_digit++;
	}
	while (second_term_digit >= 0 && sum_digit >= 0)
	{
		sum[sum_digit] = (sum[sum_digit] - '0') +
							(second_term[second_term_digit] - '0') + '0';
		second_term_digit--;
		sum_digit--;
	}
	sum = from_two_digits_to_one(sum);
	free(first_term);
	return (sum);
}

static unsigned char	*multiplication_by_digit(unsigned char *first_arg,
										unsigned int exp_digit, int decimal)
{
	unsigned char		*result_digit;
	unsigned char		*result;

	result = (unsigned char *)ft_strdup((char *)first_arg);
	result_digit = &result[ft_strlen((char *)result) - 1];
	while (result_digit >= result)
	{
		*result_digit = ((*result_digit - '0') * exp_digit) + '0';
		result_digit--;
	}
	result = from_two_digits_to_one(result);
	while (decimal > 0)
	{
		result = (unsigned char *)ft_concat_and_freehead((char *)result, "0");
		decimal--;
	}
	return (result);
}

unsigned char			*multiply(unsigned char *first_arg,
									unsigned char *second_arg)
{
	unsigned char		*result;
	unsigned char		*exp_digit;
	unsigned char		*current_result;
	int					decimal;

	result = NULL;
	decimal = 0;
	exp_digit = &second_arg[ft_strlen((char *)second_arg) - 1];
	while (exp_digit >= second_arg)
	{
		current_result = multiplication_by_digit(first_arg,
								*exp_digit - '0', decimal);
		if (!result)
			result = (unsigned char *)ft_strdup((char *)current_result);
		else
			result = addition(result, current_result);
		free(current_result);
		decimal++;
		exp_digit--;
	}
	free(first_arg);
	return (result);
}

unsigned char			*exponent_to_str(unsigned int exponent)
{
	unsigned char		*result;
	unsigned char		*term_first;
	unsigned char		*term_second;
	int					x;

	if (exponent <= 63)
		return ((unsigned char *)ft_ulltoa_base(
				(unsigned long long)1 << exponent, 10));
	else
	{
		x = (int)exponent / 63;
		term_first = (unsigned char *)ft_ulltoa_base(
				(unsigned long long)1 << 63, 10);
		while (1 < x--)
			term_first = multiply(term_first,
					(unsigned char *)"9223372036854775808");
		term_second = (unsigned char *)ft_ulltoa_base(
				(unsigned long long)1 << exponent % 63, 10);
		result = multiply(term_first, term_second);
		free(term_second);
		return (result);
	}
}
