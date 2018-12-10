/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 01:45:28 by lmonnaie           #+#    #+#             */
/*   Updated: 2018/12/10 01:45:59 by lmonnaie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include "libft/libft.h"
# define BUFF_SIZE 32
# include <sys/types.h>

int		get_next_line(const int fd, char **line);

#endif
