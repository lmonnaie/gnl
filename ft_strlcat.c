/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:48:23 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/29 14:33:29 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	j = i;
	while (src[i - j] != '\0' && i + 1 < size)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (i < size)
	{
		dst[i] = '\0';
	}
	return (j + ft_strlen(src));
}
