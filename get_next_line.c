/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:04:47 by lmonnaie          #+#    #+#             */
/*   Updated: 2019/01/11 15:07:00 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static char		*remainder;
	char *ptr;
	char *temp;

	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strnew(BUFF_SIZE + 1);
		temp = buff;
		if (remainder)
		{
			temp = ft_strjoin(remainder, buff);
			free(remainder);
		}
		if ((ptr = ft_strchr(temp, '\n')) != NULL)
		{
			*line = ft_strsub(temp, 0, (ptr-temp));
			remainder = ft_strsub(buff, (ptr-temp)+1, ft_strlen(temp));
			return (1);
		}
		else
		{
			*line = temp;
			free(temp);
			temp = ft_strnew(BUFF_SIZE + 1);
		}
	}
	return (0);
}
