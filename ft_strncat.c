/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:14:06 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/29 14:17:47 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t c;

	i = ft_strlen(s1);
	c = 0;
	while (s2[c] && c < len)
	{
		s1[i + c] = s2[c];
		c++;
	}
	s1[i + c] = '\0';
	return (s1);
}
