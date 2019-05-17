/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:04:47 by lmonnaie          #+#    #+#             */
/*   Updated: 2019/05/17 16:37:22 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remainder_handling(char **remainder, char *buff, int fd)
{
	char *temp;

	if (!(temp = ft_strjoin(remainder[fd], buff)))
		return (NULL);
	ft_strdel(&buff);
	ft_strdel(&remainder[fd]);
	return (temp);
}

char	*buff_read(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp_buff;

	if (!(temp_buff = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp_buff = ft_strjoin_free(temp_buff, buff, 1);
		if (ft_strchr(buff, '\n'))
			return (temp_buff);
	}
	if (ret == -1)
		temp_buff = NULL;
	return (temp_buff);
}

int		ft_handling(char *temp, char **remainder, int fd, char **line)
{
	char	*ptr;

	if ((ptr = ft_strchr(temp, '\n')) != NULL)
	{
		if (!(*line = ft_strsub(temp, 0, (ptr - temp))))
			return (-1);
		if (!(remainder[fd] =
			ft_strsub(temp, (ptr - temp) + 1, ft_strlen(temp) - (ptr - temp))))
			return (-1);
		ft_strdel(&temp);
		return (1);
	}
	else
	{
		if (*temp == '\0')
		{
			ft_strdel(&temp);
			return (0);
		}
		if (!(*line = ft_strdup(temp)))
			return (-1);
		ft_strdel(&temp);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*remainder[OPEN_MAX];
	char			*temp;
	int				ret;

	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	if (!(temp = buff_read(fd)))
		return (-1);
	if (remainder[fd] && remainder[fd][0] != '\0')
	{
		if (!(temp = remainder_handling(remainder, temp, fd)))
			return (-1);
	}
	ret = ft_handling(temp, remainder, fd, line);
	return (ret);
}
