/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 04:29:23 by cstripeb          #+#    #+#             */
/*   Updated: 2019/05/02 05:25:34 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, void *what, int (*f)(void *, void *, size_t))
{
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (f(lst->content, what, lst->content_size) == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
