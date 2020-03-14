/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:43:16 by cstripeb          #+#    #+#             */
/*   Updated: 2020/03/14 12:14:59 by cstripeb         ###   ########.fr       */
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

void	unit_move(t_wolf3d *wolf, t_unit *unit)
{
	if (unit->flags & 1)
	{
		if (wolf->map->grid[(int)(unit->pos.y)][(int)(unit->pos.x + unit->view.x * unit->speed)] == 0)
			unit->pos.x += unit->view.x * unit->speed;
		if (wolf->map->grid[(int)(unit->pos.y + unit->view.y * unit->speed)][(int)(unit->pos.x)] == 0)
			unit->pos.y += unit->view.y * unit->speed;
		printf("x: %f y: %f\n", unit->pos.x, unit->pos.y);
		print_map(wolf);
	}
	else if (unit->flags & (1 << 1))
	{
		if (wolf->map->grid[(int)(unit->pos.y)][(int)(unit->pos.x - unit->view.x * unit->speed)] == 0)
			unit->pos.x -= unit->view.x * unit->speed;
		if (wolf->map->grid[(int)(unit->pos.y - unit->view.y * unit->speed)][(int)(unit->pos.x)] == 0)
			unit->pos.y -= unit->view.y * unit->speed;
	}
}
