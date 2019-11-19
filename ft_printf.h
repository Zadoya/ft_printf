#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdarg.h>

typedef struct  s_specifications
{
    char    flag[6];
    int     width;
    int     precision;
    char    sign[4];
}               t_specifications;

int		        ft_printf(char *format, ...);

#endif