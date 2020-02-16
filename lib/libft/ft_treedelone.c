/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:15:13 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 18:19:48 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_treedelone(t_btree **tree, void (*del)(void *, size_t))
{
	if (tree && del)
	{
		if (*tree)
		{
			del((*tree)->content, (*tree)->content_size);
			free(*tree);
		}
		*tree = NULL;
	}
}
