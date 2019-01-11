/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonnaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:57:41 by lmonnaie          #+#    #+#             */
/*   Updated: 2018/11/27 15:43:02 by lmonnaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlist;

	if (lst)
	{
		if (!(nlist = (t_list *)malloc(sizeof(lst))))
			return (NULL);
		nlist = f(lst);
		nlist->next = ft_lstmap(lst->next, f);
		return (nlist);
	}
	return (NULL);
}
