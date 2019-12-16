/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:09:36 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/11 19:09:40 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				move_decade(char *mantissa)
{
	while (*mantissa != '.')
		mantissa++;
	*mantissa = *(mantissa + 1);
	*(mantissa + 1) = '.';
	return (*mantissa - '0');
}

static char				*main_division(char *mantissa,
							t_specifications *data, unsigned long long exponent)
{
	char				*result;
	int					i;
	unsigned long long	int_part;

	int_part = 1;
	i = 0;
	if (!(result = malloc(data->precision + 3)))
		return (NULL);
	result[data->precision + 3] = '\0';
	result[i++] = '0';
	result[i++] = '.';
	int_part = int_part * 10 + move_decade(mantissa);
	while (i < data->precision + 3)
	{
		while (int_part < exponent)
		{
			result[i++] = '0';
			int_part = int_part * 10 + move_decade(mantissa);
		}
		result[i++] = int_part / exponent + '0';
		int_part = (int_part % exponent) * 10 + move_decade(mantissa);
	}
	free(mantissa);
	return (result);
}

static char				*remove_dot_and_zeros(char **result,
												char **current_result)
{
	int					i_result;
	int					i_current_result;
	char				*return_value;
	char				*swap;

	i_result = 0;
	i_current_result = 0;
	while ((*result)[i_result] == '0' || (*result)[i_result] == '.')
		i_result++;
	return_value = ft_strsub(*result, 0, &((*result)[i_result]) - *result);
	while ((*current_result)[i_current_result] != '.')
		i_current_result++;
	i_current_result++;
	while ((*current_result)[i_current_result] == '0')
	{
		return_value = ft_concat_and_freehead(return_value, "0");
		i_current_result++;
	}
	swap = *result;
	*result = ft_strdup(&((*result)[i_result]));
	free(swap);
	swap = *current_result;
	*current_result = ft_strdup(&((*current_result)[i_current_result]));
	free(swap);
	return (return_value);
}

static char				*multiplication_with_dots(char *result,
													char *current_result)
{
	char				*tmp;

	tmp = remove_dot_and_zeros(&result, &current_result);
	result = (char *)multiply((unsigned char *)result,
								(unsigned char *)current_result);
	tmp = ft_concat_and_freehead(tmp, result);
	free(result);
	return (tmp);
}

char					*division(char *mantissa,
									long int exponent, t_specifications *data)
{
	char				*result;
	char				*current_result;
	unsigned long long	i;

	i = 1;
	if (exponent <= 63)
		result = main_division(ft_strdup(mantissa), data, i << exponent);
	else
	{
		result = main_division(ft_strdup(mantissa), data, i << 63);
		exponent -= 63;
		while (exponent > 63)
		{
			current_result = main_division(ft_strdup(mantissa), data, i << 63);
			result = multiplication_with_dots(result, current_result);
			free(current_result);
			exponent -= 63;
		}
		current_result = main_division(ft_strdup(mantissa), data,
													i << exponent);
		result = multiplication_with_dots(result, current_result);
		free(current_result);
	}
	free(mantissa);
	return (result);
}
