/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:43:16 by cstripeb          #+#    #+#             */
/*   Updated: 2020/06/30 17:08:16 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void		print_map(t_wolf3d *wolf)
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

t_vec3i		get_player_pos_integer(t_wolf3d *wolf)
{
	t_vec3i res;

	res.x = (int)(wolf->player->pos.x);
	res.y = (int)(wolf->player->pos.y);
	return (res);
}

void		unit_move(t_wolf3d *wolf, t_unit *unit)
{
	if (unit->flags & 1)
	{
		if (wolf->map->grid[(int)(unit->pos.y)]	[(int)(unit->pos.x
							+ unit->view.x * unit->speed)] == 0)
			unit->pos.x += unit->view.x * unit->speed;
		if (wolf->map->grid[(int)(unit->pos.y + unit->view.y
							* unit->speed)][(int)(unit->pos.x)] == 0)
			unit->pos.y += unit->view.y * unit->speed;
	}
	else if (unit->flags & (1 << 1))
	{
		if (wolf->map->grid[(int)(unit->pos.y)][(int)(unit->pos.x
							- unit->view.x * unit->speed)] == 0)
			unit->pos.x -= unit->view.x * unit->speed;
		if (wolf->map->grid[(int)(unit->pos.y - unit->view.y
							* unit->speed)][(int)(unit->pos.x)] == 0)
			unit->pos.y -= unit->view.y * unit->speed;
	}
}

SDL_Surface	*create_surface(int w, int h)
{
	SDL_Surface *res;

	res = SDL_CreateRGBSurface(0, w, h, 32, R_MASK, G_MASK, B_MASK, A_MASK);
	if (!res)
	{
		ft_putendl("heh");
		return (NULL);
	}
	SDL_SetSurfaceBlendMode(res, SDL_BLENDMODE_NONE);
	ft_bzero(res->pixels, res->h * res->pitch);
	return (res);
}
