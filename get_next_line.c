/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:04:47 by lmonnaie          #+#    #+#             */
/*   Updated: 2019/01/19 14:19:26 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *remainder_handling(char *remainder, char *buff)
{
	char *temp;
	temp = ft_strjoin(remainder, buff);
	free(remainder);
	return (temp);
}

char *buff_read(fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	temp = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(temp, buff);
		free(buff);
	}
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	static char		*remainder;
	char *ptr;
	char *temp;

	if (fd < 0 || fd > OPEN_MAX)
		return (-1);
	temp = buff_read(fd);
	if (remainder)
		temp = remainder_handling(remainder, temp);
	if ((ptr = ft_strchr(temp, '\n')) != NULL)
	{
		*line = ft_strsub(temp, 0, (ptr-temp));
		remainder = ft_strsub(temp, (ptr-temp)+1, ft_strlen(temp));
		return (1);
	}
	else
	{
		*line = temp;
		free(temp);
	}
	return (0);
}
