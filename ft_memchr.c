/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:37:39 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/29 14:13:03 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int t, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s != (unsigned char)t)
			++s;
		else
			return ((void *)s);
	}
	return (NULL);
}
