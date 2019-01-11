/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:30:51 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/21 13:30:34 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		min;
	int		max;
	int		len;

	if (!s)
		return (0);
	min = 0;
	while (s[min] && (s[min] == ' ' || s[min] == '\t' || s[min] == '\n'))
		min++;
	max = ft_strlen((char *)s);
	while (min < max && (s[max - 1] == ' ' || s[max - 1] == '\t' \
				|| s[max - 1] == '\n'))
		max--;
	len = max - min;
	if (min == max)
		return (ft_strnew(1));
	if (!(new = ft_strnew(len)))
		return (NULL);
	return (ft_strsub(s, min, len));
}
