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

static void	addition_assistant(char **result, int *tmp_r)
{
	(*result)[*tmp_r] = (*result)[*tmp_r] - 10;
	if ((*result)[*tmp_r - 1] == '.')
		(*result)[*tmp_r - 2] += 1;
	else if (!*tmp_r)
	{
		*result = ft_concat_and_free("0", *result);
		(*result)[*tmp_r] += 1;
		(*tmp_r)++;
	}
	else
		(*result)[*tmp_r - 1] += 1;
}

static char	*addition(char *result, char *mantissa)
{
	int		tmp_r;
	int		tmp_m;

	tmp_r = ft_strlen(result) - 1;
	tmp_m = ft_strlen(mantissa) - 1;
	while (tmp_m >= 0)
	{
		if (mantissa[tmp_m] != '.')
		{
			result[tmp_r] = result[tmp_r] + mantissa[tmp_m] - '0';
			if (result[tmp_r] > '9')
				addition_assistant(&result, &tmp_r);
		}
		tmp_m--;
		tmp_r--;
	}
	ft_putstr(result);
	return (result);
}


char		*multiplication(char *mantissa, int exponent)
{
	char	*result;

	if (exponent == 0)
		return (mantissa);
	result = ft_strdup(mantissa);
	while (exponent > 1)
	{
		result = addition(result, mantissa);
		exponent--;
	}
	free(mantissa);
	return (result);
}
