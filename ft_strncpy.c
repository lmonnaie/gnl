/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:45:41 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/29 14:34:32 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t c;

	c = 0;
	while (c < len && src[c] != '\0')
	{
		dst[c] = src[c];
		c++;
	}
	while (c < len)
	{
		dst[c] = '\0';
		c++;
	}
	return (dst);
}
