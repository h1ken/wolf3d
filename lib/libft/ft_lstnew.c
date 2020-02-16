/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:03:20 by cstripeb          #+#    #+#             */
/*   Updated: 2019/05/24 17:19:56 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	if (!(res = (t_list *)malloc(sizeof(*res))))
		return (NULL);
	res->content_size = 0;
	if (content)
	{
		if (!(res->content = malloc(content_size)))
		{
			free(res);
			return (NULL);
		}
		res->content = ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	else
		res->content = NULL;
	res->next = NULL;
	return (res);
}
