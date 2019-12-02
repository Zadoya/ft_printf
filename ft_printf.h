#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdarg.h>
#include "libft/libft.h"

typedef struct  s_specifications
{
    char    flag[6];
    int     width;
    int     precision;
    char    dot;
    char    sign[4];
}               t_specifications;

/*typedef struct  s_func_list
{
    t_func_list *next;
    void        *data_type;
    int         (*mod)(t_specifications *, va_list *);
}               t_func_list;
*/

/*ft_printf.c*/
int 	        ft_istype(char c);
int             ft_isflag(char c);
int		        formated(char **string, t_specifications *fmt);
int		        ft_printf(char *format, ...);

/*find_function.c*/
int		find_function(t_specifications *data, va_list *ap);

int		c(t_specifications *data, va_list *ap);
int		f(t_specifications *data, va_list *ap);


char*  floatToString(double num, int precision);

#endif