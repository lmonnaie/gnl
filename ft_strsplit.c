/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:22:39 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/27 15:20:52 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int i;
	int is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (*s && *s == c && is_word == 1)
		{
			is_word = 0;
			s++;
		}
		if (*s && *s != c && is_word == 0)
		{
			is_word = 1;
			i++;
		}
		if (*s != '\0')
			s++;
	}
	return (i);
}

static void		*ft_freetab(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;
	int		k;
	int		word_size;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	while (*s && i < k)
	{
		word_size = 0;
		while (*s && *s == c)
			s++;
		while (*s && s[word_size] && s[word_size] != c)
			word_size++;
		if (!(tab[i] = ft_strsub(s, 0, word_size)))
			return (ft_freetab(tab, i));
		s = s + word_size;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
