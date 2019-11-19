/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:29:05 by dorphan           #+#    #+#             */
/*   Updated: 2019/11/13 15:29:08 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_specifications
{
	char		flag[6];
	int			width;
	int			precision;
	char		sign[4];
}				t_specifications;

int 	ft_printf(const char *restrict format, ...);
int 	modifyers(char **p, va_list *ap);
int 	find_function(t_specifications *data, va_list *ap);
int		mod_id(t_specifications *data, va_list *ap);
int		mod_o(t_specifications *data, va_list *ap);
int		mod_u(t_specifications *data, va_list *ap);
int		mod_x(t_specifications *data, va_list *ap);
int		mod_c(t_specifications *data, va_list *ap);
int		mod_s(t_specifications *data, va_list *ap);
int		mod_p(t_specifications *data, va_list *ap);
int		mod_f(t_specifications *data, va_list *ap);







#endif
