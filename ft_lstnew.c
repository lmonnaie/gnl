/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:08:26 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/27 15:42:42 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlist;

	if (!(nlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	else
	{
		if (!(nlist->content = malloc(sizeof(content))))
			return (NULL);
		nlist->content = ft_memcpy((nlist->content), content, content_size);
		nlist->content_size = content_size;
	}
	nlist->next = NULL;
	return (nlist);
}
