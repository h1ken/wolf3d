/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:37:43 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 20:13:16 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treeadd(t_btree **tr, t_btree *e)
{
	if (tr)
	{
		if (!e)
			return ;
		if (*tr)
		{
			if (ft_memcmp((*tr)->content, e->content, (*tr)->content_size) < 0)
				ft_treeadd(&((*tr)->right), e);
			else
				ft_treeadd(&((*tr)->left), e);
		}
		else
			*tr = e;
	}
}
