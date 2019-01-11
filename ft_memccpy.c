/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:24:30 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/29 14:10:37 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *nsrc;
	unsigned char *ndest;

	nsrc = (unsigned char *)src;
	ndest = (unsigned char *)dst;
	while (n--)
	{
		*ndest = *nsrc;
		if (*ndest == (unsigned char)c)
			return (ndest + 1);
		nsrc++;
		ndest++;
	}
	return (NULL);
}
