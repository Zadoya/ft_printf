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

# define PRECISION 100

# include "libft/libft.h"
# include "libft/gnl/get_next_line.h"
# include <stdarg.h>

typedef struct			s_specifications
{
	char				flag[6];
	int					width;
	int					precision;
	int					dot;
	char				ch;
	unsigned char		uch;
	short				sh;
	unsigned short		ush;
	int					in;
	unsigned int		uin;
	long				ln;
	unsigned long		uln;
	long long			lnln;
	unsigned long long	ulnln;
	char				colour;
	char				sign[4];
}						t_specifications;

union					u_long_double
{
	long double			ld;
	struct
	{
		unsigned long	m : 64;
		unsigned int	e : 15;
		unsigned int	s : 1;
	}					s_parts_of_ld;
};

int						ft_printf(const char *restrict format, ...);
char					*formated(char **string, t_specifications *fmt);
int						in_case_of_dot(int *dot, t_specifications *fmt);
void					check_colour(t_specifications *data);
void					close_colour(t_specifications *data);
void					add_colour(t_specifications *fmt, char c);
int						find_function(t_specifications *data, va_list *ap);
int						mod_c(t_specifications *data, va_list *ap);
int						mod_s(t_specifications *data, va_list *ap);
int						mod_p(t_specifications *data, va_list *ap);
int						mod_id(t_specifications *data, va_list *ap);
int						print_without_minus(char **str, t_specifications *data);
int						print_in_case_of_minus(char **str,
													t_specifications *data);
int						mod_u(t_specifications *data, va_list *ap);
int						print_u(char **str, t_specifications *data);
int						print_u_minus(char **str, t_specifications *data);
int						mod_o(t_specifications *data, va_list *ap);
int						mod_x(t_specifications *data, va_list *ap);
int						print_x_minus(char **str, t_specifications *data);
int						print_x(char **str, t_specifications *data);
int						mod_ss(t_specifications *data, va_list *ap);
int						mod_b(t_specifications *data, va_list *ap);
int						print_b_minus(char **str, t_specifications *data);
int						print_b(char **str, t_specifications *data);
int						mod_file(t_specifications *data, va_list *ap);
int						mod_f(t_specifications *data, va_list *ap);
char					*divide_m(unsigned long long mantissa,
												t_specifications *data);
void					addition_to_divide_m(char **m, char **result, int *i);
char					*multiplication(char *mantissa, unsigned int exponent);
unsigned char			*multiply(unsigned char *first_arg,
												unsigned char *second_arg);
char					*division(char *mantissa, long int exponent,
														t_specifications *data);
unsigned char			*exponent_to_str(unsigned int exponent);
char					*rounding(char *result, t_specifications *data);
void					print_float(char **str, t_specifications *data);

#endif
