/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:09:47 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/21 13:29:16 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (!s || !*s || !f)
		return (0);
	if ((new = ft_strnew(ft_strlen((char *)s))) == 0)
		return (NULL);
	while (s[j])
	{
		new[j] = f(i, s[j]);
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
