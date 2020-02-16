/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:20:00 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 18:26:17 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_treedel(t_btree **tree, void (*del)(void *, size_t))
{
	if (tree && del)
	{
		if (*tree)
		{
			if ((*tree)->left)
				ft_treedel(&(*tree)->left, del);
			if ((*tree)->right)
				ft_treedel(&(*tree)->right, del);
			ft_treedelone(tree, del);
		}
	}
}
