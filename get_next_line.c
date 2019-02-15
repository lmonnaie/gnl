/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:04:47 by lmonnaie          #+#    #+#             */
/*   Updated: 2019/02/15 15:49:33 by lmonnaie         ###   ########.fr       */
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
	char	*temp_buff;

	temp_buff = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n') == NULL)
			temp_buff = ft_strjoin(temp_buff, buff);
		else
		{
			temp_buff = ft_strjoin(temp_buff, buff);
			return (temp_buff);
		}
	}
	return (temp_buff);
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
		remainder = ft_strsub(temp, (ptr-temp) + 1, ft_strlen(temp));
		return (1);
	}
	else
	{
		*line = temp;
		//free(temp);
	}
	if (line[0][0] == '\0')
		return (0);
	free(temp);
	return (1);
}
