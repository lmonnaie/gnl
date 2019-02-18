/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:04:47 by lmonnaie          #+#    #+#             */
/*   Updated: 2019/02/18 19:57:06 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remainder_handling(char *remainder, char *buff)
{
	char *temp;

	if(!(temp = ft_strjoin_free(remainder, buff, 1)))
		return (NULL);
	return (temp);
}

char	*buff_read(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp_buff;

	if(!(temp_buff = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n') == NULL)
			temp_buff = ft_strjoin_free(temp_buff, buff, 1);
		else
		{
			temp_buff = ft_strjoin_free(temp_buff, buff, 1);
			return (temp_buff);
		}
	}
	if (ret == -1)
		temp_buff = NULL;
	return (temp_buff);
}

int		get_next_line(const int fd, char **line)
{
	static char		*remainder;
	char			*ptr;
	char			*temp;

	if (fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!(temp = buff_read(fd)))
		return (-1);
	if (remainder)
		if (!(temp = remainder_handling(remainder, temp)))
		{
			ft_strdel(&temp);
			return (-1);
		}
	if ((ptr = ft_strchr(temp, '\n')) != NULL)
	{
		*line = ft_strsub(temp, 0, (ptr - temp));
		remainder = ft_strsub(temp, (ptr - temp) + 1, ft_strlen(temp));
		ft_strdel(&temp);
		return (1);
	}
	else
	{
		*line = temp;
		ft_strdel(&temp);
	}
	if (line[0][0] == '\0')
		return (0);
	return (1);
}
