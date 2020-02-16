/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:06:36 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/15 21:52:55 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_freelist(t_list **lst)
{
	t_list *tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = tmp->next;
			free(tmp);
		}
		*lst = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		if ((tmp = f(lst)))
		{
			tmp = ft_lstnew(tmp->content, tmp->content_size);
			if (!tmp)
			{
				ft_freelist(&res);
				return (NULL);
			}
			ft_lstaddlast(&res, tmp);
		}
		lst = lst->next;
	}
	return (res);
}
