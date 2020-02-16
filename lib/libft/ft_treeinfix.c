/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeinfix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:52:44 by cstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 20:11:37 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treeinfix(t_btree *tree, void (*f)(t_btree *))
{
	if (tree && f)
	{
		ft_treeinfix(tree->left, f);
		f(tree);
		ft_treeinfix(tree->right, f);
	}
}
