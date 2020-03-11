/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:43:16 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/11 17:59:41 by cstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	print_map(t_wolf3d *wolf)
{
	int i;
	int j;

	i = -1;
	printf("W: %d\t H: %d\n", wolf->map->w, wolf->map->h);
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

t_vec3i	get_player_pos_integer(t_wolf3d *wolf)
{
	t_vec3i res;

	res.x = (int)(wolf->player->pos.x);
	res.y = (int)(wolf->player->pos.y);
	return (res);
}
