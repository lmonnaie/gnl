/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:18:35 by lmonnaie          #+#    #+#             */
/*   Updated: 2019/02/08 21:38:28 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main (int argc, char **argv)
{
	char *line;
	int fd;

	line = NULL;
	if (argc != 2)
	{
		printf("mauvais arguments");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
