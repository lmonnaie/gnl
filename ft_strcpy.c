/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:35:31 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/29 14:32:45 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;
	int c;

	i = ft_strlen(src) + 1;
	c = 0;
	while (c < i)
	{
		dst[c] = src[c];
		c++;
	}
	return (dst);
}
