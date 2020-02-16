/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treepostfix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:56:22 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 20:11:19 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treepostfix(t_btree *tree, void (*f)(t_btree *))
{
	if (tree && f)
	{
		ft_treepostfix(tree->left, f);
		ft_treepostfix(tree->right, f);
		f(tree);
	}
}
