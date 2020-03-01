/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:43:16 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/01 16:47:23 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	print_map(t_wolf3d *wolf)
{
	int i;
	int j;

	i = -1;
	while (++i < wolf->map->h)
	{
		j = -1;
		while (++j < wolf->map->w)
		{
			printf("%d", wolf->map->grid[i][j]);
		}
		printf("\n");
	}
}
