/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:02:16 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/29 14:13:51 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ndest;
	unsigned char *nsrc;

	ndest = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	while (n--)
	{
		*ndest = *nsrc;
		nsrc++;
		ndest++;
	}
	return (dst);
}
