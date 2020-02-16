/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeprefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:49:48 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 20:12:03 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treeprefix(t_btree *tree, void (*f)(t_btree *))
{
	if (tree && f)
	{
		f(tree);
		ft_treeprefix(tree->left, f);
		ft_treeprefix(tree->right, f);
	}
}
