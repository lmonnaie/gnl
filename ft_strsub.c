/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:21:32 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/27 15:41:51 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;

	new = (char *)malloc(sizeof(*new) * len + 1);
	i = 0;
	if (s != NULL && new != NULL)
	{
		while (s[start + i] && len--)
		{
			new[i] = (char)s[start + i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
