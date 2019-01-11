/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:28:09 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/21 13:35:54 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int		s;

	s = 0;
	while (n != 0)
	{
		n /= 10;
		s++;
	}
	return (s);
}

char		*ft_itoa(int num)
{
	int			i;
	char		*new;
	int			count;
	long int	n;

	n = num;
	count = size(n);
	if (n < 0 || n == 0)
		count++;
	if (!(new = ft_strnew(count)))
		return (NULL);
	i = 0;
	if (n == 0)
		new[i] = '0';
	if (n < 0)
	{
		new[count - 1] = '-';
		n = -n;
	}
	while (n != 0)
	{
		new[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_reverse(new));
}
