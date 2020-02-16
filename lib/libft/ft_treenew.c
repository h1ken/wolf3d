/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:16:29 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 17:29:06 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree	*ft_treenew(void const *content, size_t content_size)
{
	t_btree *tmp;

	if (!(tmp = (t_btree *)ft_memalloc(sizeof(*tmp))))
		return (NULL);
	if (content)
	{
		if (!(tmp->content = malloc(content_size)))
		{
			free(tmp);
			return (NULL);
		}
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	return (tmp);
}
