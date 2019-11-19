/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:57:12 by jeckhard          #+#    #+#             */
/*   Updated: 2019/10/02 13:57:56 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reading(char **str, int *err, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	while (!(ft_strchr(*str, '\n')) && (*err = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[*err] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		ft_strdel(&tmp);
	}
}

int		get_line(const int fd, char **line)
{
	static char	*str[FD_MAX];
	int			err;
	size_t		eol;
	char		*tmp;

	err = 0;
	if (fd < 0 || !line || (!str[fd] && !(str[fd] = ft_strnew(1))))
		return (-1);
	reading(&str[fd], &err, (int)fd);
	if (!*(tmp = str[fd]) || err == -1)
	{
		ft_strdel(&str[fd]);
		return (err == -1 ? -1 : 0);
	}
	if ((eol = !!(ft_strchr(str[fd], '\n'))))
		*line = ft_strsub(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd]);
	else
		*line = ft_strdup(str[fd]);
	str[fd] = ft_strsub(str[fd], (unsigned int)(ft_strlen(*line) + eol),
			(size_t)(ft_strlen(str[fd]) - (ft_strlen(*line) + eol)));
	ft_strdel(&tmp);
	return (1);
}
