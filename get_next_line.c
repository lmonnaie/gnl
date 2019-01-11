/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:04:47 by lmonnaie          #+#    #+#             */
/*   Updated: 2019/01/11 14:34:41 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static char		*remainder;
	char *ptr;

	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (remainder)
		{
			buff = ft_strjoin(remainder, buff);
			free(remainder);
		}
		if ((ptr = ft_strchr(buff, '\n')) != NULL)
		{
			*line = ft_strsub(buff, 0, (ptr-buff));
			remainder = ft_strsub(buff, (ptr-buff)+1, ft_strlen(buff));
			return (1);
		}
		else
		{
			*line = buff;
			free(buff);
			buff = ft_strnew(BUFF_SIZE + 1);
		}
	}
}
